#pragma once

#include <stdint.h>>

namespace ConvertEndianNS
{

class ConvertEndian {
public:
    ConvertEndian()
    {
    }

    uint32_t convert( uint32_t value ) 
    {
        uint32_t tmp = ( (value >> 8) & 0xff00ff ) | ( ( value << 8 ) & 0xff00ff00 );
        return tmp >> 16 | tmp << 16;
    }
};

} // namespace ConvertEndian
