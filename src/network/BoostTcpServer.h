#pragma once

#include "TcpServer.h"

class BoostTcpServer : public TcpServer {
public:

    BoostTcpServer();
    ~BoostTcpServer();

    void startAcceptingConnections(std::string ip, int port, std::function<void(std::vector<std::uint8_t>)> callback) override;
    void stopAcceptingConnections() override;
};

