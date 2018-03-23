#include <gtest/gtest.h>
#include <boost/asio/io_service.hpp>
#include "game/auth/AuthService.h"

class FakeTcpServer : public TcpServer {
public:
    bool started = false;
    bool stopped = false;

    std::function<void(std::vector<std::uint8_t>)> m_callback;

    void startAcceptingConnections(std::string ip, int port, std::function<void(std::vector<std::uint8_t>)> callback) override {
        started = true;
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
    AuthService service;
    SignalListener signalListener;
    boost::asio::io_service ioService;
    CommandLineArgs commandLineArgs;
    FakeTcpServer tcpServer;

    AuthServiceTest() : commandLineArgs(0, 0), signalListener(ioService), service(commandLineArgs, tcpServer, signalListener) {
    }
};

TEST_F(AuthServiceTest, ShouldStartTcpServer) {
    service.run();
    ASSERT_TRUE(tcpServer.started);
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

