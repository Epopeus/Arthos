#include <gtest/gtest.h>
#include <common/network/NetworkInputPort.h>
#include <common/command/OpcodeCommandRouter.h>
#include "FakeNetworkConnection.h"
#include "../command/FakeCommand.h"

class NetworkInputPortTest : public ::testing::Test {
protected:
    Bytes EXPECTED_BYTES_0 = { 0, 0 };
    Bytes EXPECTED_BYTES_1 = { 1, 1 };
    Bytes EXPECTED_BYTES_2 = { 2, 2 };

    NetworkInputPortTest() {
    }
};

TEST_F(NetworkInputPortTest, ShouldSequentiallyInvokeCommandsFromReceivedPackets) {
    FakeNetworkConnection connection;

    FakeCommand command;
    FakeCommandGateway commandGateway = FakeCommandGateway(command);
    //                                   0               1               2
    BytesCommandsMap commandsMap = { commandGateway, commandGateway, commandGateway };
    OpcodeCommandRouter router = OpcodeCommandRouter(commandsMap);

    NetworkInputPort inputPort = NetworkInputPort(connection, router);
    inputPort.waitForInput();

    connection.simulateReceivedBytes(EXPECTED_BYTES_0);
    connection.simulateReceivedBytes(EXPECTED_BYTES_1);
    connection.simulateReceivedBytes(EXPECTED_BYTES_2);

    inputPort.processReceivedPackets();

    ASSERT_EQ(0, command.invokeArgs.at(0));
    ASSERT_EQ(1, command.invokeArgs.at(1));
    ASSERT_EQ(2, command.invokeArgs.at(2));
}

TEST_F(NetworkInputPortTest, ShouldHandleBadOpcodes) {

}