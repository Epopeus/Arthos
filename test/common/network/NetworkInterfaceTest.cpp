#include <gtest/gtest.h>
#include <common/network/NetworkInterface.h>
#include <common/network/boost/BoostNetworkConnectionRepository.h>
#include "FakeUUIDFactory.h"
#include "FakeNetworkServer.h"
#include "FakeNetworkClient.h"

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

    Settings EXPECTED_SETTINGS = Settings(
            { { NetworkConnectionType::GAME_CLIENT, GAME_CLIENT_PORT }, { NetworkConnectionType::AUTH_CLIENT, AUTH_CLIENT_PORT } },
            { { NetworkConnectionType::GAME_SERVER, GAME_SERVER_ENDPOINT }, { NetworkConnectionType::GAME_ROUTER, GAME_ROUTER_ENDPOINT } }
    );

    Bytes EXPECTED_BYTES = { 123, 210 };

    FakeNetworkClient networkClient;
    FakeNetworkServer networkServer;

    FakeUUIDFactory uuidFactory;
    NetworkConnectionIdFactory connectionIdFactory;
    BoostNetworkConnectionRepository connections;

    NetworkInterface networkInterface;

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

TEST_F(NetworkInterfaceTest, ShouldStoreIncomingCommandInQueue) {
    FakeNetworkConnection& connection = networkServer.simulateNewConnection(NetworkConnectionType::GAME_SERVER);

    connection.simulateReceivedBytes(EXPECTED_BYTES);

    NetworkConnectionId id = NetworkConnectionId("1");
    const NetworkConnectionEntry& entry = connections.getById(id);

    ASSERT_EQ(1, entry.receivedBytesQueue.size());
    ASSERT_EQ(EXPECTED_BYTES, entry.receivedBytesQueue.front());
}