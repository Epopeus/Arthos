#pragma once

#include "TcpServer.h"
#include "../../Service.h"
#include "SignalListener.h"
#include "AuthSettingsRepository.h"

class AuthService : public Service {
public:
    AuthService(AuthSettingsRepository& authSettingsRepository_, TcpServer &tcpServer, SignalListener &signalListener);
    ~AuthService();

    void run() override;
    void handleCommand(std::vector<uint8_t> args);

private:
    AuthSettingsRepository& authSettingsRepository;
    TcpServer& tcpServer;
    SignalListener& signalListener;
};