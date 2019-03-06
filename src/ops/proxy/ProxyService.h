#pragma once

#include <common/service/Service.h>

class ProxyService : public Service {
public:
    ProxyService(ServiceSettingsRepository& settingsRepository, TcpServer& tcpServer, TcpClient& tcpClient, SignalListener& signalListener);

protected:
    void startUp() override;
    void handleRemoteCommand(std::vector<uint8> args) override;


};

