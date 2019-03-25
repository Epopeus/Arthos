#include "BoostTcpClient.h"

BoostTcpClient::BoostTcpClient(SocketFactory& socketFactory_, ConnectionFactory& connectionFactory_):socketFactory(socketFactory_), connectionFactory(connectionFactory_) {
}

void BoostTcpClient::connect(std::string ip, int port, VoidCallback<NetworkConnection&> onConnect) {
    boost::asio::ip::tcp::endpoint endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port);

    boost::asio::ip::tcp::socket& socket = *socketFactory.create();
    socket.async_connect(endpoint, [&] (const boost::system::error_code& error) {
        if (error) {
            // TODO : handle errors
            return;
        }

        onConnect(*connectionFactory.create(socket));
    });
}