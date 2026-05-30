
#ifndef __NRF24_COMMANDS_H__
#define __NRF24_COMMANDS_H__

#include <cstdint>

enum class Command : uint8_t
{
    R_REGISTER          = 0x00,
    W_REGISTER          = 0x20,

    R_RX_PAYLOAD        = 0x61,
    W_TX_PAYLOAD        = 0xA0,

    FLUSH_TX            = 0xE1,
    FLUSH_RX            = 0xE2,

    REUSE_TX_PL         = 0xE3,

    R_RX_PL_WID         = 0x60,

    W_ACK_PAYLOAD       = 0xA8,
    W_TX_PAYLOAD_NOACK  = 0xB0,

    NOP                 = 0xFF
};


#endif
