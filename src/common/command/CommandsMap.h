#pragma once

#include "CommandGateway.h"

template<typename T>
class CommandsMap {
public:
    virtual CommandGateway<T>& getGatewayForRequest(T request) = 0;
};