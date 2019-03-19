#pragma once

#include <string>
#include <common/di/Factory.h>
#include "UUID.h"

class UUIDFactory : public Factory<UUID> {
public:
    virtual UUID create() override = 0;
};