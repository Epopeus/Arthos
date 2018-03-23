#include "AuthService.h"
#include "AuthSettings.h"

AuthService::AuthService(CommandLineArgs& commandLineArgs_, TcpServer& tcpServer_, SignalListener& signalListener_) : commandLineArgs(commandLineArgs_), tcpServer(tcpServer_), signalListener(signalListener_) {

}

AuthService::~AuthService() {
}

void AuthService::run() {
    // Parse command line args to get settings DB access parameters (ip, login, password)
    // Connect to this DB and retrieve settings
    // Map the DB settings to AuthSettings
    // Done
    AuthSettings authSettings;



    signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        tcpServer.stopAcceptingConnections();
    });

    tcpServer.startAcceptingConnections(authSettings.m_serverIp, authSettings.m_serverPort, [&] (std::vector<uint8_t> args) {
        handleCommand(args);
    });
}

void AuthService::handleCommand(std::vector<uint8_t> args) {
    std::cout << "Received ! " << std::endl;
}