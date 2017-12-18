#pragma once
#include <iostream>

class TcpServer {
public:
    virtual void startAcceptingConnections(std::string ip, int port) = 0;
    virtual void stopAcceptingConnections() = 0;
    virtual ~TcpServer() {};
};

