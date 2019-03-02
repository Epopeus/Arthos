#pragma once


#include <common/network/TcpServer.h>
#include <common/network/TcpClient.h>
#include <common/storage/Repository.h>
#include <common/service/SignalListener.h>

class Service {
public:
    Service(Repository& settingsRepository, TcpServer& tcpServer, TcpClient& tcpClient, SignalListener& signalListener);

    virtual void run() = 0;

protected:
    Repository& settingsRepository;
    TcpServer& tcpServer;
    TcpClient& tcpClient;
    SignalListener& signalListener;
};

