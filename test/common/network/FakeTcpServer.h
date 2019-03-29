#pragma once

#include <common/network/NetworkServer.h>
#include <vector>
#include "FakeNetworkConnection.h"

class FakeTcpServer : public NetworkServer {
public:
    bool started = false;
    bool stopped = false;
    std::unordered_map<NetworkConnectionType, int> ports;
    VoidCallback<NetworkConnection&> onConnect;

    void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect_) override {
        stopped = false;
        started = true;
        ports.insert({});
        onConnect = onConnect_;
    }

    void stopAcceptingConnections() override {
        started = false;
        stopped = true;
    }

    FakeNetworkConnection& simulateNewConnection(NetworkConnectionType type) {
        FakeNetworkConnection* connection = new FakeNetworkConnection();

        onConnect(*connection);

        return *connection;
    }
};