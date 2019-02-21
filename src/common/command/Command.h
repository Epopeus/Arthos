#pragma once


#include <common/entity/Guid.h>
#include "CommandArgs.h"

class Command {
public:
    Command(Guid& callingCharId);
    virtual void run(CommandArgs& args) = 0;
protected:
    Guid& callingCharId;
};

