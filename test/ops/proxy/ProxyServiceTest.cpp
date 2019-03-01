#include <gtest/gtest.h>
#include <ops/proxy/ProxyService.h>
#include "../../FakeTcpServer.h"
#include "../../FakeTcpClient.h"

class ProxyServiceTest : public ::testing::Test {
protected:
    ProxyService service;
    FakeTcpServer tcpServer;
    FakeTcpClient tcpClient;

    ProxyServiceTest() : service(tcpServer, tcpClient) {
    }
};

TEST_F(ProxyServiceTest, ShouldStartTCPListen) {
    ASSERT_TRUE(false);
}

TEST_F(ProxyServiceTest, ShouldStartTCPConnect) {
    ASSERT_TRUE(false);
}