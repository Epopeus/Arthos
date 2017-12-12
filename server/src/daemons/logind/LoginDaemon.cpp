#include "LoginDaemon.h"
#include "BoostTcpServer.h"
#include <iostream>
#include <string>


LoginDaemon::LoginDaemon(TcpServer& server) : m_server(server) {
}

LoginDaemon::~LoginDaemon() {
}

void LoginDaemon::run() {
    m_server.startAcceptingConnections();
}
