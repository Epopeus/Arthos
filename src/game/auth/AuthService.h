#pragma once

#include "common/network/TcpServer.h"
#include "common/service/Service.h"
#include "common/service/SignalListener.h"
#include "common/type/Numbers.h"

class AuthService : public Service {
public:
    AuthService(Repository& authSettingsRepository, TcpServer &tcpServer, TcpClient& tcpClient_, SignalListener &signalListener);

    void run() override;
    void handleCommand(std::vector<uint8> args);
};