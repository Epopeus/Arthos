#pragma once

#include "common/type/ValueObject.h"

class Faction : public ValueObject<uint32> {
public:
    Faction(uint32 intValue_);
};