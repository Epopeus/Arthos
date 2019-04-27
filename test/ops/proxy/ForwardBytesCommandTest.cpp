#include <gtest/gtest.h>
#include <ops/proxy/ForwardBytesCommand.h>
#include "../../common/network/FakeNetworkConnection.h"

class ForwardBytesCommandTest : public ::testing::Test {
protected:

    Bytes SENT_BYTES = {1, 2, 3};
    NetworkConnectionId CLIENT_CONNECTION_ID = NetworkConnectionId("MyClientSession");
    Bytes EXPECTED_BYTES = { CLIENT_CONNECTION_ID.toString(), 1, 2, 3};

    ForwardBytesCommandTest() {
    }
};

TEST_F(ForwardBytesCommandTest, ShouldForwardClientBytesToCorrespondingServer) {
    FakeNetworkConnection serverConnection;

    ForwardBytesCommand command = ForwardBytesCommand(CLIENT_CONNECTION_ID, serverConnection);
    command.run(SENT_BYTES);

    ASSERT_EQ(EXPECTED_BYTES, serverConnection.sentBytes.at(0));
}

TEST_F(ForwardBytesCommandTest, ShouldForwardServerBytesToCorrespondingClient) {

}