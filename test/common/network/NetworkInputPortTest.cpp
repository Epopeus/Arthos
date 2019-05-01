#include <gtest/gtest.h>
#include <common/network/NetworkInputPort.h>
#include "FakeNetworkConnection.h"

class NetworkInputPortTest : public ::testing::Test {
protected:
    Bytes EXPECTED_BYTES = { 1, 2, 3 };

    NetworkInputPortTest() {
    }
};

TEST_F(NetworkInputPortTest, ShouldStoreIncomingPacketInQueue) {
    FakeNetworkConnection connection;
    ReceivedBytesQueue receivedBytesQueue;

    NetworkInputPort inputPort = NetworkInputPort(connection, receivedBytesQueue);
    inputPort.waitForInput();

    connection.simulateReceivedBytes(EXPECTED_BYTES);

    ASSERT_EQ(1, receivedBytesQueue.size());
    ASSERT_EQ(EXPECTED_BYTES, receivedBytesQueue.front());
}