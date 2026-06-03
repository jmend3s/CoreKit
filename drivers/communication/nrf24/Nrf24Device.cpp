
#include "Nrf24Device.h"

#include "Delay.h"
#include "Nrf24Types.h"


Nrf24Device::Nrf24Device(ISpi& spi, IGpio& ce, IGpio& csn)
    : _spi(spi)
    , _ce(ce)
    , _csn(csn)
{
}

Result Nrf24Device::initialize(Config const& config)
{
    uint8_t configuration = 0;

    configuration |= ConfigBits::EnCrc;
    configuration |= ConfigBits::Crco;
    configuration |= ConfigBits::PwrUp;

    configuration = config.isReceiver ?
        configuration |= ConfigBits::PrimRx :
        configuration &= ~ConfigBits::PrimRx;

    Result result = writeRegister(Register::CONFIG, configuration);
    if (result.isOk())
    {
        Delay::ms(2);

        result = writeRegister(Register::RF_CH, config.channel);
        result = result.isOk() ? writeRegister(Register::RF_SETUP, _defaultRfSetup) : result;
        if (result.isOk())
        {
            result = writeRegisterMulti(Register::TX_ADDR, config.address, _addressLength);
            result = result.isOk() ? writeRegisterMulti(Register::RX_ADDR_P0, config.address, _addressLength) : result;
            result = result.isOk() ? writeRegister(Register::RX_PW_P0, config.payloadSize) : result; // result.assertError()?
            if (result.isOk())
            {
                result = sendCommand(Command::FLUSH_TX);
                result = result.isOk() ? sendCommand(Command::FLUSH_RX) : result;
                if (result.isOk())
                {
                    if (config.isReceiver)
                    {
                        result = startListening();
                    }
                    else
                    {
                        result = stopListening();
                    }
                }
            }
        }
    }

    return result;
}

Result Nrf24Device::send(uint8_t const* data, uint8_t const length)
{
    auto result = Result(Error::InvalidArgument);
    if (length <= _maxPayloadSize)
    {
        uint8_t tx[_maxPayloadSize + 1];
        uint8_t rx[_maxPayloadSize + 1];

        tx[0] = static_cast<uint8_t>(Command::W_TX_PAYLOAD);

        for (uint8_t i = 0; i < length; i++)
        {
            tx[i + 1] = data[i];
        }

        result = transfer(tx, rx, length + 1);
        if (result.isOk())
        {
            _ce.set(GpioState::High);
            Delay::us(_pulseUs);
            _ce.set(GpioState::Low);
        }
    }

    return result;
}

Result Nrf24Device::receive(uint8_t* data, uint8_t const length)
{
    uint8_t tx[_maxPayloadSize + 1];
    uint8_t rx[_maxPayloadSize + 1];

    tx[0] = static_cast<uint8_t>(Command::R_RX_PAYLOAD);

    for (uint8_t i = 0; i < length; i++)
    {
        tx[i + 1] = 0xFF;
    }

    Result result = transfer(tx, rx, length + 1);
    if (result.isOk())
    {
        for (uint8_t i = 0; i < length; i++)
        {
            data[i] = rx[i + 1];
        }

        result = clearStatus(StatusBits::RxDr);
    }

    return result;
}

bool Nrf24Device::available()
{
    uint8_t status;
    readStatus(status);

    return status & StatusBits::RxDr;
}

Result Nrf24Device::startListening()
{
    uint8_t configuration = 0;
    Result result = readRegister(Register::CONFIG, configuration);
    if (result.isOk())
    {
        configuration |= ConfigBits::PrimRx;
        result = writeRegister(Register::CONFIG, configuration);
        if (result.isOk())
        {
            result = clearStatus(StatusBits::RxDr | StatusBits::TxDs | StatusBits::MaxRt);
            if (result.isOk())
            {
                _ce.set(GpioState::High);
                Delay::us(_transitionUs);
            }
        }
    }

    return result;
}

Result Nrf24Device::stopListening()
{
    _ce.set(GpioState::Low);

    uint8_t configuration = 0;
    Result result = readRegister(Register::CONFIG, configuration);
    if (result.isOk())
    {
        configuration &= ~ConfigBits::PrimRx;
        result = writeRegister(Register::CONFIG, configuration);
    }

    return result;
}

Result Nrf24Device::readRegister(Register const reg, uint8_t& value)
{
    uint8_t tx[2];
    uint8_t rx[2];

    tx[0] = static_cast<uint8_t>(Command::R_REGISTER) | static_cast<uint8_t>(reg);
    tx[1] = 0xFF;

    Result const result = transfer(tx, rx, 2);
    if (result.isOk())
    {
        value = rx[1];
    }

    return result;
}

Result Nrf24Device::writeRegister(Register reg, uint8_t const value)
{
    uint8_t tx[2];
    uint8_t rx[2];

    tx[0] = static_cast<uint8_t>(Command::W_REGISTER) | static_cast<uint8_t>(reg);
    tx[1] = value;

    return transfer(tx, rx, 2);
}

Result Nrf24Device::writeRegisterMulti(Register reg, uint8_t const* data, uint8_t const length)
{
    uint8_t tx[6];
    uint8_t rx[6];

    tx[0] = static_cast<uint8_t>(Command::W_REGISTER) | static_cast<uint8_t>(reg);

    for (uint8_t i = 0; i < length; i++)
    {
        tx[i + 1] = data[i];
    }

    return transfer(tx, rx, length + 1);
}

Result Nrf24Device::sendCommand(Command const command)
{
    uint8_t tx[1];
    uint8_t rx[1];

    tx[0] = static_cast<uint8_t>(command);

    return transfer(tx, rx, 1);
}

Result Nrf24Device::readStatus(uint8_t& status)
{
    uint8_t tx[1];
    uint8_t rx[1];

    tx[0] = static_cast<uint8_t>(Command::NOP);

    Result const result = transfer(tx, rx, 1);

    if (result == Result::success())
    {
        status = rx[0];
    }

    return result;
}

Result Nrf24Device::clearStatus(uint8_t const flags)
{
    return writeRegister(Register::STATUS, flags);
}

Result Nrf24Device::transfer(const uint8_t* tx, uint8_t* rx, uint16_t const size)
{
    _csn.set(GpioState::Low);

    Result const result = _spi.transceive(tx, rx, size);

    _csn.set(GpioState::High);

    return result;
}
