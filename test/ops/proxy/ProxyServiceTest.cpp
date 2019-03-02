#include <gtest/gtest.h>
#include <ops/proxy/ProxyService.h>
#include "../../FakeTcpServer.h"
#include "../../FakeTcpClient.h"

class ProxyServiceTest : public ::testing::Test {
protected:
    ProxyService service;
    Repository settingsRepository;
    FakeTcpServer tcpServer;
    FakeTcpClient tcpClient;
    SignalListener signalListener;
    boost::asio::io_service ioService;
    DbClient dbClient;

    ProxyServiceTest() : dbClient(), settingsRepository(dbClient),
                         signalListener(ioService),
                         service(settingsRepository, tcpServer, tcpClient, signalListener) {
    }
};

TEST_F(ProxyServiceTest, ShouldStartTCPServer) {
    ASSERT_TRUE(false);
}

TEST_F(ProxyServiceTest, ShouldStartTCPClient) {
    ASSERT_TRUE(false);
}