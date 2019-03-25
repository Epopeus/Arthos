#pragma once

#include <string>
#include <common/di/Factory.h>
#include "UUID.h"

class UUIDFactory {
public:
    virtual UUID create() = 0;
};