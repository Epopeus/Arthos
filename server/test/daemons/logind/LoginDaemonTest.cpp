#include <gtest/gtest.h>
#include "daemons/logind/LoginDaemon.h"

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

TEST_F(LoginDaemonTest, ShouldStopTcpServerWhenTerminated) {
    daemon.run();
    ioService.run();

    raise(SIGTERM);
    ASSERT_TRUE(tcpServer.stopped);
}

