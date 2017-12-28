#include "AuthService.h"

AuthService::AuthService(TcpServer& tcpServer, SignalListener& signalListener) : m_tcpServer(tcpServer), m_signalListener(signalListener) {
}

AuthService::~AuthService() {
}

void AuthService::run() {
    m_signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        m_tcpServer.stopAcceptingConnections();
    });
    m_tcpServer.startAcceptingConnections("", 0, [&] (std::vector<uint8_t> args) {
        handleCommand(args);
    });
}

void AuthService::handleCommand(std::vector<uint8_t> args) {

}