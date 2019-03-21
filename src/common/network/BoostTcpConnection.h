#pragma once

#include <boost/asio.hpp>
#include "NetworkConnection.h"

class BoostTcpConnection : public NetworkConnection {
public:
    BoostTcpConnection(boost::asio::ip::tcp::socket& socket);

    void read(VoidCallback<Bytes&> onBytesReceived) override;

    void send(Bytes& bytes) override;
private:
    boost::asio::ip::tcp::socket& socket;
};

