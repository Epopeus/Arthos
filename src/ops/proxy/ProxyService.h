#pragma once


#include <common/service/Service.h>

class ProxyService : public Service {
public:
    ProxyService(Repository& settingsRepository, TcpServer& tcpServer, TcpClient& tcpClient, SignalListener& signalListener);

    void run() override;
};

