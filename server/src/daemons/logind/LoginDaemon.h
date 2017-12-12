#pragma once

#include "TcpServer.h"
#include "SignalListener.h"

class LoginDaemon {
public:
    LoginDaemon(TcpServer& server, SignalListener& signalListener);

    ~LoginDaemon();

    void run();

private:
    TcpServer& m_server;
    SignalListener& m_signalListener;

    void stop();
};

