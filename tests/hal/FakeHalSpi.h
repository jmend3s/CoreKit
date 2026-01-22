
#ifndef __FAKE_HAL_SPI_H__
#define __FAKE_HAL_SPI_H__

#include <cstdint>


struct FakeSpiState
{
    bool ready = true;

    uint8_t rx = 0xAA;

    uint8_t lastTx = 0;
    uint16_t lastSize = 0;
    int transceiveCalls = 0;
};

#endif
