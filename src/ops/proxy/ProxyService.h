#pragma once


#include <common/service/Service.h>

class ProxyService : public Service {
public:
    ProxyService(TcpServer& tcpServer, TcpClient& tcpClient);

    void run() override;
};

