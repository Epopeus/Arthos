#pragma once


#include <common/entity/Guid.h>

template<typename... TArgs>
class RemoteCommand {
public:
    virtual void run(TArgs... args) = 0;
};

