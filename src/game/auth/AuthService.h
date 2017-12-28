#pragma once

#include "TcpServer.h"
#include "../../Service.h"
#include "SignalListener.h"


class AuthService : public Service {
public:
    AuthService(TcpServer& tcpServer, SignalListener& signalListener);

    ~AuthService();

    void run() override;
    void handleCommand(std::vector<uint8_t> args);

private:
    TcpServer& m_tcpServer;
    SignalListener& m_signalListener;
};