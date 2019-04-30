#pragma once

#include <common/network/NetworkInterface.h>
#include <common/app/Settings.h>
#include "FakeNetworkConnection.h"

struct EndpointHash {
    std::size_t operator()(const Endpoint& id) const {
        size_t hash1 = std::hash<std::string>{}(id.address);
        size_t hash2 = std::hash<int>{}(id.port);
        return hash1 ^ (hash2 << 1);
    }
};

class FakeNetworkInterface : public NetworkInterface {
public:
    std::unordered_map<int, VoidCallback<NetworkConnection&>> listenPorts;
    std::unordered_map<Endpoint, VoidCallback<NetworkConnection&>, EndpointHash> connectEndpoints;

    void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect_) override;
    void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect_) override;
    void stopAcceptingConnections() override;

    void simulateNewConnectionFromConnect(Endpoint& endpoint, NetworkConnection& connection);
    void simulateNewConnectionFromListen(int port, NetworkConnection& connection);
};
