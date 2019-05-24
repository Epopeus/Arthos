#include <gtest/gtest.h>
#include <common/network/NetworkModule.h>
#include <common/network/boost/BoostNetworkConnectionRepository.h>
#include "FakeUUIDFactory.h"
#include "FakeNetworkInterface.h"
#include "../command/NullCommandRouter.h"
#include <boost/range/algorithm/copy.hpp>
#include <boost/range/adaptors.hpp>

class NetworkModuleTest : public ::testing::Test {
protected:
    int GAME_CLIENT_PORT = 1234;
    int AUTH_CLIENT_PORT = 5678;

    std::vector<int> LISTEN_PORTS = { GAME_CLIENT_PORT, AUTH_CLIENT_PORT };

    Endpoint GAME_SERVER_ENDPOINT = Endpoint("abc", 2345);
    Endpoint GAME_ROUTER_ENDPOINT = Endpoint("def", 6789);

    std::vector<Endpoint> CONNECT_ENDPOINTS = { GAME_SERVER_ENDPOINT, GAME_ROUTER_ENDPOINT };

    Settings EXPECTED_SETTINGS = Settings(
            { { NetworkConnectionType::GAME_CLIENT, GAME_CLIENT_PORT }, { NetworkConnectionType::AUTH_CLIENT, AUTH_CLIENT_PORT } },
            { { NetworkConnectionType::GAME_SERVER, GAME_SERVER_ENDPOINT }, { NetworkConnectionType::GAME_ROUTER, GAME_ROUTER_ENDPOINT } }
    );

    Bytes EXPECTED_BYTES = { 123, 210 };

    NetworkModule networkModule;
    FakeNetworkInterface networkInterface;

    FakeUUIDFactory uuidFactory;
    NetworkConnectionIdFactory connectionIdFactory;
    BoostNetworkConnectionRepository connections;

    FakeNetworkConnection connection;

    class : public Factory<NetworkConnectionEntry, NetworkConnectionId, NetworkConnection&, NetworkConnectionType> {
    public:
        NetworkConnectionEntry create(NetworkConnectionId id, NetworkConnection& connection, NetworkConnectionType type) override {
            ReceivedBytesQueue receivedBytesQueue;
            NullCommandRouter router;
            return NetworkConnectionEntry(id, connection, type, NetworkInputPort(connection, router));
        }
    } connectionEntryFactory;

    NetworkModuleTest():    connectionIdFactory(uuidFactory),
                            networkModule(EXPECTED_SETTINGS, networkInterface, connectionIdFactory, connectionEntryFactory, connections) {
        networkModule.launch();
    }
};

TEST_F(NetworkModuleTest, ShouldListenOnSettingsPorts) {
    std::vector<int> listenPorts;
    boost::copy(networkInterface.listenPorts | boost::adaptors::map_keys, std::back_inserter(listenPorts));

    ASSERT_EQ(LISTEN_PORTS, listenPorts);
}

TEST_F(NetworkModuleTest, ShouldConnectToSettingsEndpoints) {
    std::vector<Endpoint> connectEndpoints;
    boost::copy(networkInterface.connectEndpoints | boost::adaptors::map_keys, std::back_inserter(connectEndpoints));

    ASSERT_EQ(CONNECT_ENDPOINTS, connectEndpoints);
}

TEST_F(NetworkModuleTest, ShouldStoreConnections) {
    networkInterface.simulateNewConnectionFromConnect(GAME_SERVER_ENDPOINT, connection);

    NetworkConnectionId id = NetworkConnectionId("1");
    NetworkConnectionEntry& entry = connections.getById(id);

    ASSERT_EQ(NetworkConnectionType::GAME_SERVER, entry.type);
    ASSERT_EQ(&connection, &entry.connection);
}

TEST_F(NetworkModuleTest, ShouldReadConnections) {
    networkInterface.simulateNewConnectionFromConnect(GAME_SERVER_ENDPOINT, connection);

    ASSERT_TRUE(connection.startedReading);
}