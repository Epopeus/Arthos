#pragma once

#include "NetworkServer.h"
#include <common/di/Factory.h>
#include "BoostTcpFactories.h"

class BoostTcpServer : public NetworkServer {
public:
    BoostTcpServer(SocketFactory& socketFactory, ConnectionFactory& connectionFactory);

    void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect) override;
    void stopAcceptingConnections() override;

private:
    void asyncAccept();

    SocketFactory& socketFactory;
    ConnectionFactory& connectionFactory;
};

