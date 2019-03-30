#include <gtest/gtest.h>
#include <common/service/ServiceSettings.h>
#include <common/network/NetworkConnectionsMap.h>
#include <common/network/NetworkInterface.h>
#include <common/uuid/BoostUUIDFactory.h>
#include "FakeTcpClient.h"
#include "FakeTcpServer.h"
#include "../di/FakeFactory.h"

bool operator<(const Endpoint& ep1, const Endpoint& ep2) {
    return ep1.port < ep2.port;
}

class NetworkInterfaceTest : public ::testing::Test {
protected:
    int GAME_CLIENT_PORT = 1234;
    int AUTH_CLIENT_PORT = 5678;

    std::set<int> LISTEN_PORTS = { GAME_CLIENT_PORT, AUTH_CLIENT_PORT };

    Endpoint GAME_SERVER_ENDPOINT = Endpoint("abc", 2345);
    Endpoint GAME_ROUTER_ENDPOINT = Endpoint("def", 6789);

    std::set<Endpoint> CONNECT_ENDPOINTS = { GAME_SERVER_ENDPOINT, GAME_ROUTER_ENDPOINT };

    ServiceSettings EXPECTED_SETTINGS = ServiceSettings(
            { { NetworkConnectionType::GAME_CLIENT, GAME_CLIENT_PORT }, { NetworkConnectionType::AUTH_CLIENT, AUTH_CLIENT_PORT } },
            { { NetworkConnectionType::GAME_SERVER, GAME_SERVER_ENDPOINT }, { NetworkConnectionType::GAME_ROUTER, GAME_ROUTER_ENDPOINT } }
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
                            networkInterface(EXPECTED_SETTINGS, tcpClient, tcpServer, connectionIdFactory, connections) {
        networkInterface.launch();
    }
};

TEST_F(NetworkInterfaceTest, ShouldStartTcpServerWithProperSettings) {
    ASSERT_EQ(LISTEN_PORTS, tcpServer.ports);
}

TEST_F(NetworkInterfaceTest, ShouldStartTcpClientWithProperSettings) {
    ASSERT_EQ(CONNECT_ENDPOINTS, tcpClient.connectEndpoints);
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