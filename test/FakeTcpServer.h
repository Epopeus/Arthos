#pragma once

class FakeTcpServer : public TcpServer {
public:
    bool started = false;
    bool stopped = false;
    std::string ip;
    int port;

    std::function<void(std::vector<std::uint8_t>)> m_callback;

    void startAcceptingConnections(std::string ip_, int port_, std::function<void(std::vector<std::uint8_t>)> callback) override {
        started = true;
        ip = ip_;
        port = port_;
        m_callback = callback;
    }

    void stopAcceptingConnections() override {
        stopped = false;
    }


    void receiveCommand(uint8_t command) {
        m_callback({command});
    }
};