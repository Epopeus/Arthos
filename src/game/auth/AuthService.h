#pragma once

#include "TcpServer.h"
#include "../../Service.h"
#include "SignalListener.h"
#include "CommandLineArgs.h"

class AuthService : public Service {
public:
    AuthService(CommandLineArgs& commandLineArgs, TcpServer& tcpServer, SignalListener& signalListener);
    ~AuthService();

    void run() override;
    void handleCommand(std::vector<uint8_t> args);

private:
    CommandLineArgs& commandLineArgs;
    TcpServer& tcpServer;
    SignalListener& signalListener;
};