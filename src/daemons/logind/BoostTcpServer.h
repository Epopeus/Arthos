#pragma once

#include <boost/asio.hpp>
#include "BoostTcpConnection.h"
#include "TcpServer.h"

class BoostTcpServer : public TcpServer {
public:

    BoostTcpServer();

    void startAcceptingConnections() override;
    void stopAcceptingConnections() override;

private:
    void start_accept();

    void handle_accept(BoostTcpConnection::pointer new_connection,
                       const boost::system::error_code& error);

    boost::asio::ip::tcp::acceptor acceptor_;
};

