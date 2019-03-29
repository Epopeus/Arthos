#include <gtest/gtest.h>
#include <common/service/ServiceSettings.h>
#include <common/network/NetworkConnectionsMap.h>
#include <common/network/NetworkInterface.h>
#include <common/uuid/BoostUUIDFactory.h>
#include "FakeTcpClient.h"
#include "FakeTcpServer.h"
#include "../di/FakeFactory.h"

class NetworkInterfaceTest : public ::testing::Test {
protected:
    int GAME_CLIENT_PORT = 1234;
    int AUTH_CLIENT_PORT = 5678;

    std::set<int> LISTEN_PORTS = { GAME_CLIENT_PORT, AUTH_CLIENT_PORT };

    ServiceSettings EXPECTED_SETTINGS = ServiceSettings(
            { { NetworkConnectionType::GAME_CLIENT, GAME_CLIENT_PORT }, { NetworkConnectionType::AUTH_CLIENT, AUTH_CLIENT_PORT } },
            { { NetworkConnectionType::GAME_SERVER, Endpoint("abc", 9123) }, { NetworkConnectionType::GAME_ROUTER, Endpoint("def", 4567) } }
    );

    uint8_t EXPECTED_COMMAND = 123;

    FakeTcpClient tcpClient;
    FakeTcpServer tcpServer;

    NetworkConnectionsMap connections;

    NetworkInterface networkInterface;

    NetworkConnectionIdFactory connectionIdFactory;

    boost::uuids::random_generator generator;
    BoostUUIDFactory uuidFactory;

    NetworkInterfaceTest(): uuidFactory(generator),
                            connectionIdFactory(uuidFactory),
                            networkInterface(EXPECTED_SETTINGS, tcpClient, tcpServer, connectionIdFactory, connections){
    }
};

TEST_F(NetworkInterfaceTest, ShouldStartTcpServerWithProperSettings) {
    networkInterface.launch();

    ASSERT_TRUE(tcpServer.started);

    ASSERT_EQ(LISTEN_PORTS, tcpServer.ports);
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