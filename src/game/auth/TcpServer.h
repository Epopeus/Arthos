#pragma once
#include <functional>
#include <vector>

class TcpServer {
public:
    virtual void startAcceptingConnections(std::string ip, int port, std::function<void(std::vector<std::uint8_t>)> callback) = 0;
    virtual void stopAcceptingConnections() = 0;
    virtual ~TcpServer() {};
};

