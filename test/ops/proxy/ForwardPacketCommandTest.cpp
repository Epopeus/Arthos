#include <gtest/gtest.h>
#include <ops/proxy/ForwardPacketCommand.h>
#include <common/network/Bytes.h>
#include <ops/network/ClientServerMap.h>
#include "../../common/network/FakeNetworkConnection.h"
#include "../../common/command/FakeCommandOutputBuffer.h"

class ForwardPacketCommandTest : public ::testing::Test {
protected:

    Bytes SENT_BYTES = {1, 2, 3};
    //NetworkConnectionId CLIENT_SESSION_ID = "MyClientSession";
    //NetworkConnectionId SERVER_SESSION_ID = "MyServerSession";

    ForwardPacketCommandTest() {
    }
};

TEST_F(ForwardPacketCommandTest, ShouldForwardClientPacketsToCorrespondingServer) {
    /*FakeNetworkConnection clientConnection = FakeNetworkConnection();
    NetworkSession clientSession = NetworkSession(clientConnection);

    FakeNetworkConnection serverConnection = FakeNetworkConnection();
    NetworkSession serverSession = NetworkSession(serverConnection);

    NetworkConnectionsMap sessions = NetworkConnectionsMap();
    sessions.add(CLIENT_SESSION_ID, clientSession),
    sessions.add(SERVER_SESSION_ID, serverSession);

    ClientServerMap clientServerMap = ClientServerMap();
    clientServerMap.add(CLIENT_SESSION_ID, SERVER_SESSION_ID);

    FakeCommandOutputBuffer outputBuffer = FakeCommandOutputBuffer();

    ForwardPacketCommand command = ForwardPacketCommand(sessions, clientServerMap, outputBuffer);
    command.run(CLIENT_SESSION_ID, SENT_BYTES);

    Bytes expectedBytes = SENT_BYTES;
    expectedBytes.insert(expectedBytes.begin(), CLIENT_SESSION_ID);

    ASSERT_EQ(expectedBytes, serverConnection.sentBytes);*/
}

TEST_F(ForwardPacketCommandTest, ShouldForwardServerPacketsToCorrespondingClient) {

}