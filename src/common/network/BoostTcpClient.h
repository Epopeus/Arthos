#pragma once

#include "NetworkClient.h"
#include <common/di/Factory.h>
#include "BoostTcpConnection.h"

using SocketFactory = Factory<boost::asio::ip::tcp::socket&>;
using ConnectionFactory = Factory<BoostTcpConnection&, boost::asio::ip::tcp::socket&>;

class BoostTcpClient : public NetworkClient {
public:
    BoostTcpClient(SocketFactory& socketFactory, ConnectionFactory& connectionFactory);

    void connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect) override;

private:
    SocketFactory& socketFactory;
    ConnectionFactory& connectionFactory;
};

