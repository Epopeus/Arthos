#include <gtest/gtest.h>
#include <ops/proxy/ForwardClientBytesCommand.h>
#include "../../common/network/FakeNetworkConnection.h"

class ForwardClientBytesCommandTest : public ::testing::Test {
protected:

    Bytes SENT_BYTES = {1, 2, 3};
    NetworkConnectionId CLIENT_CONNECTION_ID = NetworkConnectionId("MyClientSession");
    Bytes EXPECTED_BYTES = { CLIENT_CONNECTION_ID.toString(), 1, 2, 3};

    FakeNetworkConnection serverConnection;

    ForwardClientBytesCommandTest() {
    }
};

/**
 * Since the business rules say literally forward bytes, we don't have an adapter layer here
 */
TEST_F(ForwardClientBytesCommandTest, ShouldForwardClientBytesToCorrespondingServer) {
    ForwardClientBytesCommand command = ForwardClientBytesCommand(CLIENT_CONNECTION_ID, serverConnection);
    command.run(SENT_BYTES);

    ASSERT_EQ(EXPECTED_BYTES, serverConnection.sentBytes.at(0));
}