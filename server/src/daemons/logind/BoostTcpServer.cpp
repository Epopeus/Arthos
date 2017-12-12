#include "BoostTcpServer.h"

BoostTcpServer::BoostTcpServer() : acceptor_((*new boost::asio::io_service()), boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 3724)) {

}


void BoostTcpServer::startAcceptingConnections() {
    while (1) {
        boost::asio::ip::tcp::iostream stream;
        acceptor_.accept(*stream.rdbuf());
        std::cout << "Received !" << std::endl;
    }

}

void BoostTcpServer::start_accept()
{
    BoostTcpConnection::pointer new_connection =
            BoostTcpConnection::create(acceptor_.get_io_service());

    acceptor_.async_accept(new_connection->socket(),
                           boost::bind(&BoostTcpServer::handle_accept, this, new_connection,
                                       boost::asio::placeholders::error));


}

void BoostTcpServer::handle_accept(BoostTcpConnection::pointer new_connection,
                   const boost::system::error_code& error)
{
    if (!error)
    {
        new_connection->start();
    }

    std::cout << "Received ! " << std::endl;
    start_accept();


    /** Main
      try
     {
         boost::asio::io_service io_service;
         BoostTcpServer server(io_service);
         io_service.run();
     }
     catch (std::exception& e)
     {
         std::cout << std::string(e.what()) << std::endl;
     }
     **/
}