#pragma once

#include <vector>
#include <common/type/Numbers.h>
#include <string>
#include <variant>

using AllowedType = std::variant<uint8, uint16, uint32, uint64, int8, int16, int32, int64, float, double, std::string>;

class Bytes {
public:
    Bytes(std::initializer_list<AllowedType> values);

    Bytes& operator<<(AllowedType value);
    void prepend(AllowedType value);

    bool operator==(const Bytes &o) const;

private:
    std::vector<AllowedType> buffer;
};