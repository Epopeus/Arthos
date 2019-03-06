#include <iostream>
#include "ProxyService.h"

ProxyService::ProxyService(ServiceSettingsRepository& settingsRepository_, TcpServer &tcpServer_, TcpClient& tcpClient_, SignalListener& signalListener_):Service(settingsRepository_, tcpServer_, tcpClient_, signalListener_) {
}

void ProxyService::startUp() {
}

void ProxyService::handleRemoteCommand(std::vector<uint8> args) {
    std::cout << "Received ! " << std::endl;
}
