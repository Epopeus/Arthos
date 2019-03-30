#pragma once

#include <common/network/NetworkClient.h>
#include <unordered_map>

class FakeTcpClient : public NetworkClient {
public:
    std::set<Endpoint> connectEndpoints;

    VoidCallback<NetworkConnection&> onConnect;

    void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect_) override {
        connectEndpoints.emplace(ip, port);
        onConnect = onConnect_;
    }

    void receiveBinaryData(std::vector<uint8> binaryData) {
    }
};