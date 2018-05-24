#pragma once

#include "common/network/TcpServer.h"
#include "common/service/Service.h"
#include "SignalListener.h"
#include "AuthSettingsRepository.h"
#include "common/type/Numbers.h"

class AuthService : public Service {
public:
    AuthService(AuthSettingsRepository& authSettingsRepository_, TcpServer &tcpServer, SignalListener &signalListener);
    ~AuthService();

    void run() override;
    void handleCommand(std::vector<uint8> args);

private:
    AuthSettingsRepository& authSettingsRepository;
    TcpServer& tcpServer;
    SignalListener& signalListener;
};