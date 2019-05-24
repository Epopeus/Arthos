#pragma once

#include <common/entity/Guid.h>

class GameClientCommand {
public:
    GameClientCommand(Guid& callingCharId_):callingCharId(callingCharId_) {

    }
protected:
    Guid& callingCharId;
};