#include <gtest/gtest.h>
#include <common/network/NetworkModule.h>
#include <common/network/boost/BoostNetworkConnectionRepository.h>
#include "FakeUUIDFactory.h"
#include "FakeNetworkInterface.h"


class NetworkModuleTest : public ::testing::Test {
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

    FakeUUIDFactory uuidFactory;
    NetworkConnectionIdFactory connectionIdFactory;
    BoostNetworkConnectionRepository connections;

    NetworkModule networkModule;
    FakeNetworkInterface networkInterface;

    NetworkModuleTest(): connectionIdFactory(uuidFactory),
                            networkModule(EXPECTED_SETTINGS, networkInterface, connectionIdFactory, connections) {
        networkModule.launch();
    }
};

TEST_F(NetworkModuleTest, ShouldStartNetworkServerWithProperSettings) {
    ASSERT_EQ(LISTEN_PORTS, networkInterface.listenPorts);
}

TEST_F(NetworkModuleTest, ShouldStartNetworkClientWithProperSettings) {
    ASSERT_EQ(CONNECT_ENDPOINTS, networkInterface.connectEndpoints);
}

TEST_F(NetworkModuleTest, ShouldStoreIncomingCommandInQueue) {
    FakeNetworkConnection& connection = networkInterface.simulateNewConnection(NetworkConnectionType::GAME_SERVER);

    connection.simulateReceivedBytes(EXPECTED_BYTES);

    NetworkConnectionId id = NetworkConnectionId("1");
    const NetworkConnectionEntry& entry = connections.getById(id);

    ASSERT_EQ(1, entry.receivedBytesQueue.size());
    ASSERT_EQ(EXPECTED_BYTES, entry.receivedBytesQueue.front());
}