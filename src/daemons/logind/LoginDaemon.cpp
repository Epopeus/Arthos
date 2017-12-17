#include "LoginDaemon.h"
#include <boost/asio.hpp>
LoginDaemon::LoginDaemon(TcpServer &server, SignalListener &m_signalListener) : m_server(server), m_signalListener(m_signalListener) {
}

LoginDaemon::~LoginDaemon() {
}


void LoginDaemon::run() {
    m_signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        m_server.stopAcceptingConnections();
    });

    m_server.startAcceptingConnections();
}

