#pragma once


#include <common/network/TcpServer.h>
#include <common/network/TcpClient.h>

class Service {
public:
    Service(TcpServer& tcpServer, TcpClient& tcpClient);
    virtual ~Service() {};

    virtual void run() = 0;

protected:
    TcpServer& tcpServer;
    TcpClient& tcpClient;
};

