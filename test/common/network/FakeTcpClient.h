#pragma once

#include <common/network/TcpClient.h>

class FakeTcpClient : public TcpClient {
public:
    bool connected = false;
    std::string connectIp;
    int connectPort;

    void connect(std::string ip_, int port_, std::function<void(std::vector<uint8>)> callback) override {
        connected = true;
        connectIp = ip_;
        connectPort = port_;
    }
};