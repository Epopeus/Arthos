#pragma once

#include "CommandsMap.h"

template<class T>
class CommandRouter {
public:
    CommandRouter(CommandsMap<T>& commandsMap):commandsMap(commandsMap) {

    }

    void route(T request) {
        CommandAdapter<T>& adapter = commandsMap.getAdapterForRequest(request);
        adapter.run(request);
    }

private:
    CommandsMap<T>& commandsMap;
};