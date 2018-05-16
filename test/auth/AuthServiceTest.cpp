#include <gtest/gtest.h>
#include <boost/asio/io_service.hpp>
#include <common/service/CommandLineArgs.h>
#include "game/auth/AuthService.h"

class FakeTcpServer : public TcpServer {
public:
    bool started = false;
    bool stopped = false;
    std::string ip;
    int port;

    std::function<void(std::vector<std::uint8_t>)> m_callback;

    void startAcceptingConnections(std::string ip_, int port_, std::function<void(std::vector<std::uint8_t>)> callback) override {
        started = true;
        ip = ip_;
        port = port_;
        m_callback = callback;
    }

    void stopAcceptingConnections() override {
        stopped = false;
    }


    void receiveCommand(uint8_t command) {
        m_callback({command});
    }
};


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

