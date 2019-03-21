#pragma once

#include "NetworkServer.h"
#include "BoostTcpConnection.h"
#include <common/di/Factory.h>

using SocketFactory = Factory<boost::asio::ip::tcp::socket&>;
using ConnectionFactory = Factory<BoostTcpConnection&, boost::asio::ip::tcp::socket&>;

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

