
#ifndef __NRF24_DEVICE_H__
#define __NRF24_DEVICE_H__

#include "IGpio.h"
#include "ISpi.h"
#include "Nrf24Registers.h"
#include "Nrf24Commands.h"
#include "Result.h"

#include <cstdint>


class Nrf24Device
{
public:
    struct Config
    {
        bool receiver;
        uint8_t payloadSize;
    };

    Nrf24Device(ISpi& spi, IGpio& ce, IGpio& csn, Config config);

    Result initialize(bool isReceiver);

    bool available();

    Result powerUp();
    Result powerDown();

    Result startListening();
    Result stopListening();

    Result send(uint8_t const* data, uint8_t length);
    Result receive(uint8_t* data, uint8_t length);

    Result clearStatus(uint8_t flags);

private:
    Result transfer(uint8_t const* tx, uint8_t* rx, uint16_t size);

    Result writeRegisterMulti(Register reg, uint8_t const* data, uint8_t length);
    Result readRegister(Register reg, uint8_t& value);
    Result writeRegister(Register reg, uint8_t value);

    Result sendCommand(Command command);
    Result readStatus(uint8_t& status);

    static uint8_t constexpr _maxPayloadSize = 32;
    static uint8_t constexpr _addressSize = 5;

    ISpi& _spi;
    IGpio& _ce;
    IGpio& _csn;

    Config _config;
};

#endif
