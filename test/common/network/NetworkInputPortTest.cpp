#include <gtest/gtest.h>
#include <common/network/NetworkInputPort.h>
#include <game/world/WorldCommandsMap.h>
#include "FakeNetworkConnection.h"
#include "../command/FakeCommand.h"
#include "../command/FakeCommandsMap.h"

class NetworkInputPortTest : public ::testing::Test {
protected:
    Bytes EXPECTED_BYTES_1 = { 1 };
    Bytes EXPECTED_BYTES_2 = { 2 };
    Bytes EXPECTED_BYTES_3 = { 3 };

    NetworkInputPortTest() {
    }
};

TEST_F(NetworkInputPortTest, ShouldSequentiallyInvokeGatewaysFromReceivedPackets) {
    FakeNetworkConnection connection;

    FakeCommandGateway gateway;
    FakeCommandsMap commandsMap = FakeCommandsMap(gateway);
    CommandRouter<Bytes&> router = CommandRouter(commandsMap);

    NetworkInputPort inputPort = NetworkInputPort(connection, router);
    inputPort.waitForInput();

    connection.simulateReceivedBytes(EXPECTED_BYTES_1);
    connection.simulateReceivedBytes(EXPECTED_BYTES_2);
    connection.simulateReceivedBytes(EXPECTED_BYTES_3);

    inputPort.processReceivedPackets();

    ASSERT_EQ(EXPECTED_BYTES_1, gateway.invokeArgs.at(0));
    ASSERT_EQ(EXPECTED_BYTES_2, gateway.invokeArgs.at(1));
    ASSERT_EQ(EXPECTED_BYTES_3, gateway.invokeArgs.at(2));
}

TEST_F(NetworkInputPortTest, ShouldHandleBadOpcodes) {
    ASSERT_TRUE(false);
}