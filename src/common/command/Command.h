#pragma once


#include <common/entity/Guid.h>

class Command {
public:
    Command(Guid& playerId);

protected:
    Guid& playerId;
};

