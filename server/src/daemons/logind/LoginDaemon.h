#pragma once

#include "TcpServer.h"
#include "BoostTcpServer.h"

class LoginDaemon {
public:
    LoginDaemon(TcpServer& server);

    ~LoginDaemon();

    void run();
private:
    TcpServer& m_server;
    bool stop;
};

