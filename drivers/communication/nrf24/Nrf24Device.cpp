
#include "Nrf24Device.h"

Result Nrf24Device::transfer(const uint8_t* tx, uint8_t* rx, uint16_t const size)
{
    _csn.set(GpioState::Low);

    Result const result = _spi.transceive(tx, rx, size);

    _csn.set(GpioState::High);

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
