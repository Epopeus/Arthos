#include "AuthService.h"

AuthService::AuthService(TcpServer& tcpServer) : m_tcpServer(tcpServer) {
}

AuthService::~AuthService() {
}

void AuthService::run() override {
    m_tcpServer.startAcceptingConnections("", 0);
}