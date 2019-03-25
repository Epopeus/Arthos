#include <gtest/gtest.h>
#include <common/service/ServiceSettings.h>
#include <common/network/NetworkConnectionsMap.h>
#include "FakeTcpClient.h"
#include "FakeTcpServer.h"

class NetworkInterfaceTest : public ::testing::Test {
protected:

    ServiceSettings EXPECTED_SETTINGS = ServiceSettings(
            { { NetworkConnectionType::GAME_CLIENT, 1234 }, { NetworkConnectionType::AUTH_CLIENT, 5678 } },
            { { NetworkConnectionType::GAME_SERVER, Endpoint("abc", 9123) }, { NetworkConnectionType::GAME_ROUTER, Endpoint("def", 4567) } }
    );

    uint8_t EXPECTED_COMMAND = 123;

    FakeTcpClient tcpClient;
    FakeTcpServer tcpServer;

    NetworkConnectionsMap connections;

    NetworkInterfaceTest() {
    }
};

TEST_F(NetworkInterfaceTest, ShouldStartTcpServerWithProperSettings) {
    ASSERT_TRUE(tcpServer.started);

    //ASSERT_EQ(EXPECTED_SETTINGS.listenPorts, tcpServer.ports);

}

TEST_F(NetworkInterfaceTest, ShouldStartTcpClientWithProperSettings) {
    ASSERT_TRUE(tcpClient.connected);
    //ASSERT_EQ(EXPECTED_SETTINGS.connectEndpoints, tcpClient.connectEndpoints);
}

TEST_F(NetworkInterfaceTest, ShouldStoreNewIncomingConnection) {
    tcpServer.simulateNewConnection(NetworkConnectionType::AUTH_CLIENT);

    //ASSERT_NO_THROW(connections.;
}

TEST_F(NetworkInterfaceTest, ShouldHandleRemoteCommandFromTcpServer) {
    //networkServer.receiveCommand(EXPECTED_COMMAND);

    //ASSERT_EQ(EXPECTED_COMMAND, service.lastReceivedCommand.at(0));
}

TEST_F(NetworkInterfaceTest, ShouldHandleRemoteCommandFromTcpClient) {
    tcpClient.receiveBinaryData({EXPECTED_COMMAND});

    //ASSERT_EQ(EXPECTED_COMMAND, service.lastReceivedCommand.at(0));
}