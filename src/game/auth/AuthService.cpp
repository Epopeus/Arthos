#include <iostream>
#include "AuthService.h"

AuthService::AuthService(AuthSettingsRepository& authSettingsRepository_, TcpServer &tcpServer_, TcpClient& tcpClient_, SignalListener &signalListener_) : Service(tcpServer_, tcpClient_), authSettingsRepository(authSettingsRepository_), signalListener(signalListener_) {

}

AuthService::~AuthService() {
}

void AuthService::run() {
    AuthSettings authSettings = authSettingsRepository.getAuthSettings();

    tcpServer.startAcceptingConnections(authSettings.serverIp, authSettings.serverPort, [&] (std::vector<uint8> args) {
        handleCommand(args);
    });

    signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        tcpServer.stopAcceptingConnections();
    });
}

void AuthService::handleCommand(std::vector<uint8> args) {
    std::cout << "Received ! " << std::endl;
}