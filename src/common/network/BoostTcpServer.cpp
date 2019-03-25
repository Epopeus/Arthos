#include "BoostTcpServer.h"

BoostTcpServer::BoostTcpServer(SocketFactory& socketFactory_, ConnectionFactory& connectionFactory_):socketFactory(socketFactory_), connectionFactory(connectionFactory_) {

}

typedef struct AUTH_LOGON_CHALLENGE_C
{

    uint8 cmd;
    uint8 error;
    uint16 size;
    uint8 gamename[4];
    uint8 version[3];
    uint8 build_1;
    uint8 build_2;
    uint8 platform[4];
    uint8 os[4];
    uint8 country[4];
    uint32 timezone_bias;
    uint32 ip;
    uint8 I_len;

    /*
    uint8 opCode;
    uint8 error;
    uint8 size_1;
    uint8 size_2;
    uint8 gamename_1;
    uint8 gamename_2;
    uint8 gamename_3;
    uint8 gamename_4;
    uint8 version_1;
    uint8 version_2;
    uint8 version_3;
    uint8 build;
    uint8 platform_1;
    uint8 platform_2;
    uint8 platform_3;
    uint8 platform_4;
    uint8 os_1;
    uint8 os_2;
    uint8 os_3;
    uint8 os_4;
    uint8 country_1;
    uint8 country_2;
    uint8 country_3;
    uint8 country_4;
    uint8 timezone_bias_1;
    uint8 timezone_bias_2;
    uint8 timezone_bias_3;
    uint8 timezone_bias_4;
    uint8 ip_1;
    uint8 ip_2;
    uint8 ip_3;
    uint8 ip_4;
    uint8 I_len;
    */

} sAuthLogonChallenge_C;

void BoostTcpServer::startAcceptingConnections(int port, VoidCallback<NetworkConnection&> onConnect) {
    boost::asio::ip::tcp::endpoint endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v6(), port);
    boost::asio::io_context ioContext = boost::asio::io_context();
    boost::asio::ip::tcp::acceptor acceptor(ioContext, endpoint);

    asyncAccept();

    //
    //
    //
    //
    //
    // ENDIAN CONVERT ?????
    //
    //
    //
    //
    //
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
}

void BoostTcpServer::asyncAccept() {
    boost::asio::ip::tcp::socket& socket = *socketFactory.create();
    boost::asio::ip::v6_only option(false);
    socket.set_option(option);

    /*acceptor.async_accept(socket, [&] (const boost::system::error_code& error) {
        if (error) {
            // TODO : handle errors
            return;
        }

        onConnect(connectionFactory.create(socket));


    });*/
}


void BoostTcpServer::stopAcceptingConnections() {

}


