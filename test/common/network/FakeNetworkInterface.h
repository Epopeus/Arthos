#pragma once

#include <common/network/NetworkInterface.h>
#include <common/app/Settings.h>
#include "FakeNetworkConnection.h"
#include <set>

class FakeNetworkInterface : public NetworkInterface {
public:
    std::set<int> listenPorts;
    std::set<Endpoint> connectEndpoints;
    VoidCallback<NetworkConnection&> onConnect;

    void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect_) override;
    void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect_) override;
    void stopAcceptingConnections() override;

    FakeNetworkConnection& simulateNewConnection(NetworkConnectionType type);
};
