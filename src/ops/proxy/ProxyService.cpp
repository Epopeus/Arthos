#include <iostream>
#include "ProxyService.h"

ProxyService::ProxyService(TcpServer& tcpServer_, TcpClient& tcpClient_):Service(tcpServer_, tcpClient_) {
}

void ProxyService::run() {
    // Start TCP listen to talk to client
    // Start TCP connect to talk to game services

}