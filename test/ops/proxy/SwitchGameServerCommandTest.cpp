#include <gtest/gtest.h>
#include <ops/proxy/SwitchGameServerCommand.h>
#include <common/app/Settings.h>

class SwitchGameServerCommandTest : public ::testing::Test {
protected:
    const Endpoint EXPECTED_ENDPOINT = Endpoint("123", 456);

    SwitchGameServerCommandTest() {
    }
};

TEST_F(SwitchGameServerCommandTest, ShouldAskGameRouterForGameServerWhenNewConnectionOccurs) {

}
TEST_F(SwitchGameServerCommandTest, ShouldSwitchGameServerWhenRequested) {
    /*SwitchGameServerCommand command = SwitchGameServerCommand();

    command.run();
    ASSERT_TRUE(tcpClient.connected);
    ASSERT_EQ(EXPECTED_SETTINGS.connectAddress, tcpClient.connectIp);
    ASSERT_EQ(EXPECTED_SETTINGS.connectPort, tcpClient.connectPort);*/
}