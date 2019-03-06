#include "Service.h"

Service::Service(ServiceSettingsRepository& settingsRepository_, ServiceSettings& settings_, TcpServer& tcpServer_, TcpClient& tcpClient_, SignalListener& signalListener_):settingsRepository(settingsRepository_), settings(settings_), tcpServer(tcpServer_), tcpClient(tcpClient_), signalListener(signalListener_) {

}

void Service::run() {
    startUp();

    settingsRepository.loadFromDataSource();

    tcpServer.startAcceptingConnections(settings.listenPort, [&] (std::vector<uint8> args) {
        handleRemoteCommand(args);
    });

    tcpClient.connect(settings.connectAddress, settings.connectPort, [&] (std::vector<uint8> args) {
        handleRemoteCommand(args);
    });

    signalListener.startListeningForSignals({SIGTERM, SIGINT}, [&]() {
        tcpServer.stopAcceptingConnections();
    });
}