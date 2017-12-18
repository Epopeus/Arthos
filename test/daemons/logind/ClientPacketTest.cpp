#include <gtest/gtest.h>
#include "auth/ClientPacket.h"

class ClientPacketTest : public ::testing::Test {
protected:

    ClientPacketTest() {
    }
};

TEST_F(ClientPacketTest, ShouldParseOpcode) {
    uint8_t expectedOpcode = 0x05;
    ClientPacket clientPacket({expectedOpcode, 0x01, 0x02, 0x03, 0x04});

    ASSERT_EQ(clientPacket.getOpcode(), expectedOpcode);
}