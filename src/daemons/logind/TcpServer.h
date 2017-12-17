#pragma once


class TcpServer {
public:
    virtual void startAcceptingConnections() = 0;
    virtual void stopAcceptingConnections() = 0;
    virtual ~TcpServer() {};
};

