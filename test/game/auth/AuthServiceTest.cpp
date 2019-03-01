#include <gtest/gtest.h>
#include <boost/asio/io_service.hpp>
#include <common/service/CommandLineArgs.h>
#include "game/auth/AuthService.h"
#include "../../FakeTcpServer.h"


class AuthServiceTest : public ::testing::Test {
protected:
    const std::string SERVER_BIND_IP = "123.456.789";
    const int SERVER_BIND_PORT = 1234;

    static const int NUM_ARGS = 1;
    const char* ARGS[NUM_ARGS] = {0};

    AuthService service;
    SignalListener signalListener;
    boost::asio::io_service ioService;
    CommandLineArgs commandLineArgs;
    FakeTcpServer tcpServer;
    AuthSettingsRepository authSettingsRepository;
    DbConnectionURI dbConnectionURI;
    DbClient dbClient;
    AuthServiceTest() : signalListener(ioService),
                        commandLineArgs(NUM_ARGS, ARGS),
                        dbConnectionURI(), dbClient(dbConnectionURI), authSettingsRepository(dbClient),
                        service(authSettingsRepository, tcpServer, signalListener)
                         {
    }
};

TEST_F(AuthServiceTest, ShouldRetrieveSettings) {
    service.run();


}
TEST_F(AuthServiceTest, ShouldStartTcpServerWithProperSettings) {
    service.run();

    //ASSERT_EQ(SERVER_BIND_IP, tcpServer.ip);
    //ASSERT_EQ(SERVER_BIND_PORT, tcpServer.port);
}

/*
 * TODO : this is problematic because signals are global and hard to test.
 * Figure out a elegant way to test that the server proberly stops when receiving SIGTERM, SIGINT, etc.

TEST_F(LoginDaemonTest, ShouldStopTcpServerWhenTerminated) {
    daemon.run();
    ioService.run();

    raise(SIGTERM);
    ASSERT_TRUE(tcpServer.stopped);
}

TEST_F(LoginDaemonTest, ShouldStopTcpServerWhenInterrupted) {
    daemon.run();
    ioService.run();

    raise(SIGINT);
    ASSERT_TRUE(tcpServer.stopped);
}
 */

