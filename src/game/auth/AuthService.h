#pragma once

#include "common/app/App.h"

class AuthService : public App {
public:
    AuthService(SettingsRepository& settingsRepository, NetworkServer &tcpServer, NetworkClient& tcpClient_, SignalListener &signalListener);

protected:
    void startUp() override;
    void handleRemoteCommand(std::vector<uint8> args) override;

};