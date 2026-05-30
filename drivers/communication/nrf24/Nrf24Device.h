
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
    Nrf24Device(ISpi& spi, IGpio& ce, IGpio& csn);

    Result initialize();

    Result powerUp();
    Result powerDown();

    Result startListening();
    Result stopListening();

    Result flushTx();
    Result flushRx();

    Result send(uint8_t const * data, uint8_t len);
    Result receive(uint8_t * data, uint8_t& len);

private:
    Result transfer(uint8_t const* tx, uint8_t* rx, uint16_t size);

    Result readRegister(Register reg, uint8_t& value);
    Result writeRegister(Register reg, uint8_t value);

    Result sendCommand(Command command);
    Result readStatus(uint8_t& status);

    ISpi& _spi;
    IGpio& _ce;
    IGpio& _csn;
};

#endif
