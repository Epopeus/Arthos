#pragma once


#include <common/entity/Guid.h>
#include "RemoteCommand.h"

template<typename... TArgs>
class GameClientCommand : public RemoteCommand<TArgs...> {
public:
    GameClientCommand(Guid& callingCharId_):callingCharId(callingCharId_) {

    }
    virtual void run(TArgs... args) = 0;
protected:
    Guid& callingCharId;
};

