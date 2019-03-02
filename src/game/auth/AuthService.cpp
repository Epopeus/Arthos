#include <iostream>
#include "AuthService.h"
#include "AuthSettings.h"

AuthService::AuthService(Repository& settingsRepository_, TcpServer &tcpServer_, TcpClient& tcpClient_, SignalListener& signalListener_) : Service(settingsRepository_, tcpServer_, tcpClient_, signalListener_) {

}


void AuthService::run() {
    AuthSettings authSettings = settingsRepository.get<AuthSettings>();

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