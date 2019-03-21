#pragma once

#include <common/network/NetworkClient.h>
#include <unordered_map>

class FakeTcpClient : public NetworkClient {
public:
    bool connected = false;
    std::vector<Endpoint> connectEndpoints;

    VoidCallback<NetworkConnection&> onConnect;

    void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect_) override {
        connected = true;
        connectEndpoints.emplace_back(ip, port);
        onConnect = onConnect_;
    }

    void receiveBinaryData(std::vector<uint8> binaryData) {
    }
};