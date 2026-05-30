
#include "Spi.h"


Spi::Spi(SpiSpec& spec)
    : _spi(spec)
{
}

Result Spi::write(uint8_t const* tx, uint16_t const size)
{
    return transceive(tx, nullptr, size);
}

Result Spi::read(uint8_t* rx, uint16_t const size)
{
    return transceive(nullptr, rx, size);
}

Result Spi::transceive(uint8_t const* tx, uint8_t* rx, uint16_t const size)
{
    Result result = Result::fail(Error::NotReady);
    if (_spi.isReady())
    {
        if ((tx == nullptr && rx == nullptr) || size == 0)
        {
            result = Result::fail(Error::InvalidArgument);
        }
        else
        {
            int const ret = _spi.transceive(const_cast<uint8_t*>(tx), rx, size);
            result = ret == 0 ? Result::success() : Result::fail(Error::Communication);
        }
    }

    return result;
}
