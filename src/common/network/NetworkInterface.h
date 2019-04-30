#pragma once

#include <string>
#include "NetworkConnection.h"

class NetworkInterface {
public:
    virtual void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect) = 0;
    virtual void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect) = 0;
    virtual void stopAcceptingConnections() = 0;
};
