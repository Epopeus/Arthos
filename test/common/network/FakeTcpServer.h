#pragma once

#include <common/network/TcpServer.h>

class FakeTcpServer : public TcpServer {
public:
    bool started = false;
    bool stopped = false;
    int port;

    std::function<void(std::vector<std::uint8_t>)> m_callback;

    void startAcceptingConnections(int port_, std::function<void(std::vector<std::uint8_t>)> callback) override {
        stopped = false;
        started = true;
        port = port_;
        m_callback = callback;
    }

    void stopAcceptingConnections() override {
        started = false;
        stopped = true;
    }


    void receiveCommand(uint8_t command) {
        m_callback({command});
    }
};