#pragma once


#include "ServiceSettingsRepository.h"
#include <common/network/TcpServer.h>
#include <common/network/TcpClient.h>
#include <common/service/SignalListener.h>

class Service {
public:
    Service(ServiceSettingsRepository& settingsRepository, ServiceSettings& settings_, TcpServer& tcpServer, TcpClient& tcpClient, SignalListener& signalListener);

    void run();
protected:
    virtual void startUp() = 0;
    virtual void handleRemoteCommand(std::vector<uint8> args) = 0;

    ServiceSettingsRepository& settingsRepository;
    ServiceSettings& settings;
    TcpServer& tcpServer;
    TcpClient& tcpClient;
    SignalListener& signalListener;
};

