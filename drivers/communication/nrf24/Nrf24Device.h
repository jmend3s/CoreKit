
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
        bool isReceiver;
        uint8_t payloadSize;
        uint8_t channel;
        uint8_t address[5];
    };

    Nrf24Device(ISpi& spi, IGpio& ce, IGpio& csn);

    Result initialize(Config const& config);

    Result send(uint8_t const* data, uint8_t length);
    Result receive(uint8_t* data, uint8_t length);

    bool available();

private:
    Result startListening();
    Result stopListening();

    Result readRegister(Register reg, uint8_t& value);
    Result writeRegister(Register reg, uint8_t value);
    Result writeRegisterMulti(Register reg, uint8_t const* data, uint8_t length);

    Result sendCommand(Command command);

    Result readStatus(uint8_t& status);
    Result clearStatus(uint8_t flags);

    Result transfer(uint8_t const* tx, uint8_t* rx, uint16_t size);

    ISpi& _spi;
    IGpio& _ce;
    IGpio& _csn;

    static uint8_t constexpr _defaultRfSetup = 0x06;

    static uint8_t constexpr _maxPayloadSize = 32;
    static uint8_t constexpr _addressLength = 5;

    static uint8_t constexpr _transitionUs = 150;
    static uint8_t constexpr _pulseUs = 20;
};

#endif
