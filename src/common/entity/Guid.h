#pragma once

#include <common/type/ValueObject.h>

class Guid : public ValueObject<uint64> {
public:
    Guid(uint64 intValue_);
};