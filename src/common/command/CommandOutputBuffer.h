#pragma once

#include <common/type/Numbers.h>
#include <string>
#include <variant>

using AllowedType = std::variant<uint8, uint16, uint32, uint64, int8, int16, int32, int64, float, double, std::string>;

class CommandOutputBuffer {
    virtual CommandOutputBuffer& operator<<(AllowedType value) = 0;
};
