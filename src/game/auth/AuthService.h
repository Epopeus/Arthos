#pragma once

#include "TcpServer.h"
#include "../../Service.h"

class AuthService : public Service {
public:
    AuthService(TcpServer& tcpServer);

    ~AuthService();

    void run() override;
private:
    TcpServer& m_tcpServer;
};