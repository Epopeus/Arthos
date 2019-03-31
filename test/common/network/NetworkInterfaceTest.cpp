#include <gtest/gtest.h>
#include <common/service/ServiceSettings.h>
#include <common/network/NetworkConnectionsMap.h>
#include <common/network/NetworkInterface.h>
#include <common/uuid/BoostUUIDFactory.h>
#include "FakeNetworkClient.h"
#include "FakeNetworkServer.h"
#include "../di/FakeFactory.h"
#include "FakeUUIDFactory.h"

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

    FakeNetworkClient networkClient;
    FakeNetworkServer networkServer;

    NetworkConnectionsMap connections;

    NetworkInterface networkInterface;

    NetworkConnectionIdFactory connectionIdFactory;

    FakeUUIDFactory uuidFactory;

    NetworkInterfaceTest(): connectionIdFactory(uuidFactory),
                            networkInterface(EXPECTED_SETTINGS, networkClient, networkServer, connectionIdFactory, connections) {
        networkInterface.launch();
    }
};

TEST_F(NetworkInterfaceTest, ShouldStartNetworkServerWithProperSettings) {
    ASSERT_EQ(LISTEN_PORTS, networkServer.ports);
}

TEST_F(NetworkInterfaceTest, ShouldStartNetworkClientWithProperSettings) {
    ASSERT_EQ(CONNECT_ENDPOINTS, networkClient.connectEndpoints);
}

TEST_F(NetworkInterfaceTest, ShouldStoreNewIncomingConnections) {
    networkServer.simulateNewConnection(NetworkConnectionType::AUTH_CLIENT);
    networkServer.simulateNewConnection(NetworkConnectionType::GAME_SERVER);

    NetworkConnectionId id = NetworkConnectionId("1");
    ASSERT_NO_THROW(connections.getById(id));

    id = NetworkConnectionId("2");
    ASSERT_NO_THROW(connections.getById(id));
}

TEST_F(NetworkInterfaceTest, ShouldHandleRemoteCommandFromNetworkServer) {
    //networkServer.receiveCommand(EXPECTED_COMMAND);

    //ASSERT_EQ(EXPECTED_COMMAND, service.lastReceivedCommand.at(0));
}

TEST_F(NetworkInterfaceTest, ShouldHandleRemoteCommandFromNetworkClient) {
    //networkClient.receiveBinaryData({EXPECTED_COMMAND});

    //ASSERT_EQ(EXPECTED_COMMAND, service.lastReceivedCommand.at(0));
}