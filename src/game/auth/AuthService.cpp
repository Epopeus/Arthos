#include <iostream>
#include "AuthService.h"

AuthService::AuthService(ServiceSettingsRepository& settingsRepository_, NetworkServer &tcpServer_, NetworkClient& tcpClient_, SignalListener& signalListener_) : Service(settingsRepository_, tcpServer_, tcpClient_, signalListener_) {

}

void AuthService::startUp() {

}

void AuthService::handleRemoteCommand(std::vector<uint8> args) {
    std::cout << "Received ! " << std::endl;
}