#pragma once

#include <common/entity/Guid.h>
#include "Command.h"

template<typename... TArgs>
class GameClientCommand : public Command<TArgs...> {
public:
    GameClientCommand(Guid& callingCharId_):callingCharId(callingCharId_) {

    }
    virtual void run(TArgs... args) = 0;
protected:
    Guid& callingCharId;
};