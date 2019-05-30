#pragma once

#include "CommandAdapter.h"

template<typename T>
class CommandsMap {
public:
    virtual CommandAdapter<T>& getAdapterForRequest(T request) = 0;
};