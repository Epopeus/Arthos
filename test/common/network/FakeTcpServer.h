#pragma once

#include <common/network/NetworkServer.h>
#include <vector>
#include "FakeNetworkConnection.h"

class FakeTcpServer : public NetworkServer {
public:
    std::set<int> ports;
    VoidCallback<NetworkConnection&> onConnect;

    void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect_) override {
        ports.insert(port);
        onConnect = onConnect_;
    }

    void stopAcceptingConnections() override {
    }

    FakeNetworkConnection& simulateNewConnection(NetworkConnectionType type) {
        FakeNetworkConnection* connection = new FakeNetworkConnection();

        onConnect(*connection);

        return *connection;
    }
};