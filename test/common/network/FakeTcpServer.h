#pragma once

#include <common/network/TcpServer.h>

class FakeTcpServer : public TcpServer {
public:
    bool started = false;
    bool stopped = false;
    int port;

    std::function<void(std::vector<std::uint8_t>)> callback;

    void startAcceptingConnections(int port_, std::function<void(std::vector<std::uint8_t>)> callback_) override {
        stopped = false;
        started = true;
        port = port_;
        callback = callback_;
    }

    void stopAcceptingConnections() override {
        started = false;
        stopped = true;
    }

    void receiveCommand(uint8_t command) {
        callback({command});
    }
};