#pragma once

#include "common/service/Service.h"

class AuthService : public Service {
public:
    AuthService(ServiceSettingsRepository& settingsRepository, NetworkServer &tcpServer, NetworkClient& tcpClient_, SignalListener &signalListener);

protected:
    void startUp() override;
    void handleRemoteCommand(std::vector<uint8> args) override;

};