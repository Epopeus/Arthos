#pragma once

#include "NetworkConnectionId.h"
#include "NetworkConnection.h"

class NetworkConnections {
public:
    virtual void add(NetworkConnectionId, NetworkConnection& connection) = 0;
    virtual NetworkConnection& getById(NetworkConnectionId& id) = 0;
};