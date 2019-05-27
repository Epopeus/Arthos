#pragma once

#include "CommandsMap.h"

template<class T>
class CommandRouter {
public:
    CommandRouter(CommandsMap<T>& commandsMap):commandsMap(commandsMap) {

    }

    void route(T request) {
        CommandGateway<T>& gateway = commandsMap.getGatewayForRequest(request);
        gateway.run(request);
    }

private:
    CommandsMap<T>& commandsMap;
};