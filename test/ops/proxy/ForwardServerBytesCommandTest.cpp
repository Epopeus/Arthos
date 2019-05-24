#include <gtest/gtest.h>
#include <common/network/boost/BoostNetworkConnectionRepository.h>
#include <ops/proxy/ForwardServerBytesCommand.h>
#include "../../common/network/FakeNetworkConnection.h"
#include "../../common/command/NullCommandRouter.h"

class ForwardServerBytesCommandTest : public ::testing::Test {
protected:
    NetworkConnectionId CLIENT_CONNECTION_ID = NetworkConnectionId("MyClientConnection");
    Bytes SENT_BYTES = {CLIENT_CONNECTION_ID.toString(), 1, 2, 3};
    Bytes EXPECTED_BYTES = {1, 2, 3};

    ForwardServerBytesCommandTest() {
    }
};


TEST_F(ForwardServerBytesCommandTest, ShouldForwardServerBytesToCorrespondingClient) {
    FakeNetworkConnection clientConnection;
    NullCommandRouter commandRouter;
    NetworkInputPort inputPort = NetworkInputPort(clientConnection, commandRouter);
    NetworkConnectionEntry clientConnectionEntry = NetworkConnectionEntry(CLIENT_CONNECTION_ID, clientConnection, NetworkConnectionType::GAME_CLIENT, inputPort);

    BoostNetworkConnectionRepository connections;
    connections.add(clientConnectionEntry);

    ForwardServerBytesCommand command = ForwardServerBytesCommand(connections);
    command.run(SENT_BYTES);

    ASSERT_EQ(EXPECTED_BYTES, clientConnection.sentBytes.at(0));
}