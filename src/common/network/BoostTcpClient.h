#pragma once

#include "NetworkClient.h"
#include <common/di/Factory.h>
#include "BoostTcpFactories.h"


class BoostTcpClient : public NetworkClient {
public:
    BoostTcpClient(SocketFactory& socketFactory, ConnectionFactory& connectionFactory);

    void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect) override;

private:
    SocketFactory& socketFactory;
    ConnectionFactory& connectionFactory;
};

