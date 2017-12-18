#include <gtest/gtest.h>
#include "auth/LoginDaemon.h"

class FakeTcpServer : public TcpServer {
public:
    bool started = false;
    bool stopped = false;

    void startAcceptingConnections() override {
        started = true;
    }

    void stopAcceptingConnections() override {
        stopped = false;
    }
};

class LoginDaemonTest : public ::testing::Test {
protected:
    LoginDaemon daemon;
    FakeTcpServer tcpServer;
    boost::asio::io_service ioService;
    SignalListener signalListener;

    LoginDaemonTest() : signalListener(ioService), daemon(tcpServer, signalListener) {
    }
};


TEST_F(LoginDaemonTest, ShouldStartTcpServer) {
    daemon.run();
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

