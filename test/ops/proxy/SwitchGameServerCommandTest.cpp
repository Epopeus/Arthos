#include <gtest/gtest.h>
#include <ops/proxy/SwitchGameServerCommand.h>

class SwitchGameServerCommandTest : public ::testing::Test {
protected:

    SwitchGameServerCommandTest() {
    }
};

TEST_F(SwitchGameServerCommandTest, ShouldAskGameRouterForGameServerWhenNewConnectionOccurs) {

}
TEST_F(SwitchGameServerCommandTest, ShouldSwitchGameServerWhenRequested) {
    /*SwitchGameServerCommand command = SwitchGameServerCommand(EXPECTED_SETTINGS.connectAddress, EXPECTED_SETTINGS.connectPort);
    tcpClient.receiveCommand({command});
    ASSERT_TRUE(tcpClient.connected);
    ASSERT_EQ(EXPECTED_SETTINGS.connectAddress, tcpClient.connectIp);
    ASSERT_EQ(EXPECTED_SETTINGS.connectPort, tcpClient.connectPort);*/
}