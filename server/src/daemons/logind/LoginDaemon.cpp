#include "LoginDaemon.h"
#include "BoostTcpServer.h"
#include <iostream>
#include <string>


LoginDaemon::LoginDaemon(TcpServer &server) : server(server) {
}

LoginDaemon::~LoginDaemon() {
}

void LoginDaemon::run() {
    server.startAcceptingConnections();
}
