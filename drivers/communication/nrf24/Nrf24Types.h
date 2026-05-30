
#ifndef __NRF24_TYPES_H__
#define __NRF24_TYPES_H__

#include <cstdint>


namespace Nrf24ConfigBits
{
    uint8_t constexpr PrimRx   = (1u << 0);
    uint8_t constexpr PwrUp    = (1u << 1);

    uint8_t constexpr Crco     = (1u << 2);
    uint8_t constexpr EnCrc    = (1u << 3);

    uint8_t constexpr MaskMaxRt = (1u << 4);
    uint8_t constexpr MaskTxDs  = (1u << 5);
    uint8_t constexpr MaskRxDr  = (1u << 6);
}

namespace Nrf24StatusBits
{
    uint8_t constexpr TxFull = (1u << 0);

    uint8_t constexpr MaxRt  = (1u << 4);
    uint8_t constexpr TxDs   = (1u << 5);
    uint8_t constexpr RxDr   = (1u << 6);
}


#endif
