#include "BoostTcpServer.h"
#include <iostream>

BoostTcpServer::BoostTcpServer() : acceptor_((*new boost::asio::io_service()), boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 3724)) {

}


void BoostTcpServer::startAcceptingConnections() {
    boost::asio::ip::tcp::iostream stream;
    acceptor_.accept(*stream.rdbuf());

    std::uint8_t opCode;
    std::uint8_t error;
    std::uint16_t size;
    std::uint8_t gamename[4];
    std::uint8_t version[3];
    std::uint16_t build;
    std::uint8_t platform[4];
    std::uint8_t os[4];
    std::uint8_t country[4];
    std::uint32_t timezone_bias;
    std::uint32_t ip;
    std::uint8_t I_len;
    stream.read(reinterpret_cast<char*>(&opCode), sizeof opCode);
    stream.read(reinterpret_cast<char*>(&error), sizeof error);
    stream.read(reinterpret_cast<char*>(&size), sizeof size);
    stream.read(reinterpret_cast<char*>(&gamename), sizeof gamename);
    stream.read(reinterpret_cast<char*>(&version), sizeof version);
    stream.read(reinterpret_cast<char*>(&build), sizeof build);
    stream.read(reinterpret_cast<char*>(&platform), sizeof platform);
    stream.read(reinterpret_cast<char*>(&os), sizeof os);
    stream.read(reinterpret_cast<char*>(&country), sizeof country);
    stream.read(reinterpret_cast<char*>(&timezone_bias), sizeof timezone_bias);
    stream.read(reinterpret_cast<char*>(&ip), sizeof ip);
    stream.read(reinterpret_cast<char*>(&I_len), sizeof I_len);
    std::uint8_t I[8];
    stream.read(reinterpret_cast<char*>(&I), sizeof I);
    std::cout << "Received login challenge !"  << std::endl;
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
