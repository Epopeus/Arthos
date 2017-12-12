#include <gtest/gtest.h>
#include "daemons/logind/LoginDaemon.h"
#include "daemons/logind/TcpServer.h"

class FakeTcpServer : public TcpServer {
public:
    bool startedAcceptingConnections = false;

    void startAcceptingConnections() override {
        startedAcceptingConnections = true;
    }
};

class LoginDaemonTest : public ::testing::Test {
protected:
    LoginDaemon daemon;
    FakeTcpServer tcpServer;

    LoginDaemonTest() : tcpServer(FakeTcpServer()), daemon(LoginDaemon(tcpServer)) {
    }
};

TEST_F(LoginDaemonTest, ShouldAcceptClientConnection) {
    daemon.run();
    ASSERT_TRUE(tcpServer.startedAcceptingConnections);
}
