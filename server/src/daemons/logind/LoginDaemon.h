#pragma once

#include "TcpServer.h"

class LoginDaemon {
public:
    LoginDaemon(TcpServer&);

    ~LoginDaemon();

    void run();
private:
    TcpServer& server;
    bool stop;
};

