#pragma once

#include "common/service/Service.h"

class AuthService : public Service {
public:
    AuthService(ServiceSettingsRepository& settingsRepository, TcpServer &tcpServer, TcpClient& tcpClient_, SignalListener &signalListener);

protected:
    void startUp() override;
    void handleRemoteCommand(std::vector<uint8> args) override;

};