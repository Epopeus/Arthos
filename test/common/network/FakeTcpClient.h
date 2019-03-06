#pragma once

#include <common/network/TcpClient.h>

class FakeTcpClient : public TcpClient {
public:
    bool connected = false;
    std::string connectIp;
    int connectPort;

    std::function<void(std::vector<std::uint8_t>)> callback;

    void connect(std::string ip_, int port_, std::function<void(std::vector<uint8>)> callback_) override {
        connected = true;
        connectIp = ip_;
        connectPort = port_;
        callback = callback_;
    }

    void receiveCommand(uint8_t command) {
        callback({command});
    }
};