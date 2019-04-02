#pragma once

#include <common/network/NetworkServer.h>
#include <set>
#include "FakeNetworkConnection.h"

class FakeNetworkServer : public NetworkServer {
public:
    std::set<int> ports;
    VoidCallback<NetworkConnection&> onConnect;

    void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect_) override;
    void stopAcceptingConnections() override;

    FakeNetworkConnection& simulateNewConnection(NetworkConnectionType type);
};