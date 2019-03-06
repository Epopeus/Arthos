#pragma once

#include "TcpServer.h"

class BoostTcpServer : public TcpServer {
public:

    BoostTcpServer();
    ~BoostTcpServer();

    void startAcceptingConnections(int port, std::function<void(std::vector<uint8>)> callback) override;
    void stopAcceptingConnections() override;
};

