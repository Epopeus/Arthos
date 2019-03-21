#pragma once

#include <common/VoidCallback.h>
#include "NetworkConnection.h"

class NetworkServer {
public:
    virtual void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect) = 0;
    virtual void stopAcceptingConnections() = 0;
};