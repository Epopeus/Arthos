#pragma once
#include <common/VoidCallback.h>
#include "NetworkConnection.h"

class NetworkClient {
public:
    virtual void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect) = 0;
};