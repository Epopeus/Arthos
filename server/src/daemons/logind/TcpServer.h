#pragma once


class TcpServer {
public:
    virtual void startAcceptingConnections() = 0;
    virtual ~TcpServer() {};
};

