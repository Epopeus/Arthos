#pragma once

#include <common/network/NetworkInterface.h>
#include "BoostTcpFactories.h"

class BoostNetworkInterface : public NetworkInterface {
    BoostNetworkInterface(SocketFactory& socketFactory, ConnectionFactory& connectionFactory);

    void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect) override;
    void startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect) override;
    void stopAcceptingConnections() override;

private:
    void asyncAccept();

    SocketFactory& socketFactory;
    ConnectionFactory& connectionFactory;
};
