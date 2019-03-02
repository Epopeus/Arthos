#include <iostream>
#include "ProxyService.h"

ProxyService::ProxyService(Repository& settingsRepository_, TcpServer &tcpServer_, TcpClient& tcpClient_, SignalListener& signalListener_):Service(settingsRepository_, tcpServer_, tcpClient_, signalListener_) {
}

void ProxyService::run() {
    // Start TCP listen to talk to client
    // Start TCP connect to talk to game services

}