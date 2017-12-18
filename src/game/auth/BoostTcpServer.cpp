#include "BoostTcpServer.h"
#include <iostream>

BoostTcpServer::BoostTcpServer() : m_acceptor((*new boost::asio::io_service()), boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 3724)) {
}

typedef struct AUTH_LOGON_CHALLENGE_C
{

    std::uint8_t cmd;
    std::uint8_t error;
    std::uint16_t size;
    std::uint8_t gamename[4];
    std::uint8_t version[3];
    std::uint8_t build_1;
    std::uint8_t build_2;
    std::uint8_t platform[4];
    std::uint8_t os[4];
    std::uint8_t country[4];
    std::uint32_t timezone_bias;
    std::uint32_t ip;
    std::uint8_t I_len;

    /*
     * std::uint8_t opCode;
    std::uint8_t error;
    std::uint8_t size_1;
    std::uint8_t size_2;
    std::uint8_t gamename_1;
    std::uint8_t gamename_2;
    std::uint8_t gamename_3;
    std::uint8_t gamename_4;
    std::uint8_t version_1;
    std::uint8_t version_2;
    std::uint8_t version_3;
    std::uint8_t build;
    std::uint8_t platform_1;
    std::uint8_t platform_2;
    std::uint8_t platform_3;
    std::uint8_t platform_4;
    std::uint8_t os_1;
    std::uint8_t os_2;
    std::uint8_t os_3;
    std::uint8_t os_4;
    std::uint8_t country_1;
    std::uint8_t country_2;
    std::uint8_t country_3;
    std::uint8_t country_4;
    std::uint8_t timezone_bias_1;
    std::uint8_t timezone_bias_2;
    std::uint8_t timezone_bias_3;
    std::uint8_t timezone_bias_4;
    std::uint8_t ip_1;
    std::uint8_t ip_2;
    std::uint8_t ip_3;
    std::uint8_t ip_4;
    std::uint8_t I_len;
     */

} sAuthLogonChallenge_C;

void BoostTcpServer::startAcceptingConnections(std::string ip, int port) {
    boost::asio::ip::tcp::iostream stream;
        m_acceptor.accept(*stream.rdbuf());
    // Read first bit : it's the command
    //
    std::vector<uint8_t> buf;
    sAuthLogonChallenge_C test;

    stream.read(reinterpret_cast<char *>(&test), 38);

/*
    stream.read(reinterpret_cast<char *>(&test.opCode), 1);
    stream.read(reinterpret_cast<char *>(&test.error), 1);
    stream.read(reinterpret_cast<char *>(&test.size_1), 1);
    stream.read(reinterpret_cast<char *>(&test.size_2), 1);
    stream.read(reinterpret_cast<char *>(&test.gamename_1), 1);
    stream.read(reinterpret_cast<char *>(&test.gamename_2), 1);
    stream.read(reinterpret_cast<char *>(&test.gamename_3), 1);
    stream.read(reinterpret_cast<char *>(&test.gamename_4), 1);
    stream.read(reinterpret_cast<char *>(&test.version_1), 1);
    stream.read(reinterpret_cast<char *>(&test.version_2), 1);
    stream.read(reinterpret_cast<char *>(&test.version_3), 1);
    stream.read(reinterpret_cast<char *>(&test.build_1), 1);
    stream.read(reinterpret_cast<char *>(&test.build_2), 1);
    stream.read(reinterpret_cast<char *>(&test.platform_1), 1);
    stream.read(reinterpret_cast<char *>(&test.platform_2), 1);
    stream.read(reinterpret_cast<char *>(&test.platform_3), 1);
    stream.read(reinterpret_cast<char *>(&test.platform_4), 1);
    stream.read(reinterpret_cast<char *>(&test.os_1), 1);
    stream.read(reinterpret_cast<char *>(&test.os_2), 1);
    stream.read(reinterpret_cast<char *>(&test.os_3), 1);
    stream.read(reinterpret_cast<char *>(&test.os_4), 1);
    stream.read(reinterpret_cast<char *>(&test.country_1), 1);
    stream.read(reinterpret_cast<char *>(&test.country_2), 1);
    stream.read(reinterpret_cast<char *>(&test.country_3), 1);
    stream.read(reinterpret_cast<char *>(&test.country_4), 1);
    stream.read(reinterpret_cast<char *>(&test.timezone_bias_1), 1);
    stream.read(reinterpret_cast<char *>(&test.timezone_bias_2), 1);
    stream.read(reinterpret_cast<char *>(&test.timezone_bias_3), 1);
    stream.read(reinterpret_cast<char *>(&test.timezone_bias_4), 1);
    stream.read(reinterpret_cast<char *>(&test.ip_1), 1);
    stream.read(reinterpret_cast<char *>(&test.ip_2), 1);
    stream.read(reinterpret_cast<char *>(&test.ip_3), 1);
    stream.read(reinterpret_cast<char *>(&test.ip_4), 1);
    stream.read(reinterpret_cast<char *>(&test.I_len), 1);
*/

    std::cout << "Received !" << std::endl;
}


void BoostTcpServer::stopAcceptingConnections() {

}
void BoostTcpServer::start_accept()
{
    BoostTcpConnection::pointer new_connection =
            BoostTcpConnection::create(m_acceptor.get_io_service());

    m_acceptor.async_accept(new_connection->socket(),
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
