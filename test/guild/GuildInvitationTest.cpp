#include <gtest/gtest.h>
#include <game/guild/EventPacket.h>
#include "common/network/PacketDeliveryServer.h"
#include "game/guild/Invitation.h"

class FakePacketDeliveryServer : public PacketDeliveryServer {
public:
    FakePacketDeliveryServer():sentPackets() {
    }

    virtual void send(std::unique_ptr<ServerPacket> packet) {
        sentPackets.push_back(std::move(packet));
    }

    std::vector<std::unique_ptr<ServerPacket>> sentPackets;
};

/**
 * TODO :
 * Our tests inputs should be binary data from a fake client.
 * Assertions should be made on the output binary data sent to the fake client or/and on state that was muted.
 * This way we can cover greater ground with our unit tests.
 */
class GuildInvitationTest : public ::testing::Test {
public:
    GuildInvitationTest():
            invitedPlayerId(Guid(123)),
            invitedPlayerName("Test"),
            invitedPlayerCurrentRoster(Guild::Roster()),
            invitedPlayerFaction(Faction(0)),

            invitingPlayerId(Guid(456)),
            invitingPlayerRoster(Guild::Roster()),
            invitingPlayerFaction(Faction(0)),

            clock(Clock()),
            log(Guild::Log(clock)),
            packetDeliveryServer(FakePacketDeliveryServer()),

            invitation(Guild::Invitation(invitingPlayerId, invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerName, invitedPlayerCurrentRoster, invitedPlayerFaction, log, packetDeliveryServer))
            {

            }

    Guid invitedPlayerId;
    Name invitedPlayerName;
    Guild::Roster invitedPlayerCurrentRoster;
    Faction invitedPlayerFaction;

    Guid invitingPlayerId;
    Guild::Roster invitingPlayerRoster;
    Faction invitingPlayerFaction;

    Clock clock;
    Guild::Log log;
    FakePacketDeliveryServer packetDeliveryServer;

    Guild::Invitation invitation;
};

TEST_F(GuildInvitationTest, AddsMemberToRosterWhenInvitationIsAccepted) {
    invitation.accept();

    ASSERT_TRUE(invitingPlayerRoster.hasMember(invitedPlayerId));
}

TEST_F(GuildInvitationTest, LogsWhenInvitationSucceded) {
    invitation.accept();

    /*Guild::LogEvent* event = (Guild::LogEvent*)log.getEvents().at(0);
    ASSERT_EQ(Guild::LogEvent::Type::NEW_MEMBER, event.type);
    ASSERT_EQ(invitingPlayerId, event.playerGuid1);
    ASSERT_EQ(invitedPlayerId, event.playerGuid2);*/
}

TEST_F(GuildInvitationTest, InformsRosterWhenInvitationSucceded) {
    invitation.accept();

    Guild::EventPacket* packet  = (Guild::EventPacket*)packetDeliveryServer.sentPackets.at(0).get();

    ASSERT_EQ(Guild::EventPacket::Type::NEW_MEMBER, packet->type);
    ASSERT_EQ(invitedPlayerId, *packet->playerGuid);
    ASSERT_EQ(invitedPlayerName, packet->miscStrings.at(0));
}

TEST_F(GuildInvitationTest, FailsWhenPlayerIsMember) {
    invitingPlayerRoster.add(invitedPlayerId);

    invitation.accept();

    ASSERT_EQ(1, invitingPlayerRoster.getNumberOfMembers());
}

TEST_F(GuildInvitationTest, FailsWhenPlayerIsInOtherGuild) {
    invitedPlayerCurrentRoster.add(invitedPlayerId);

    invitation.accept();

    ASSERT_FALSE(invitingPlayerRoster.hasMember(invitedPlayerId));
}

TEST_F(GuildInvitationTest, FailsWhenPlayerBelongsToOtherFaction) {
    invitedPlayerFaction = Faction(1);

    invitation.accept();

    ASSERT_FALSE(invitingPlayerRoster.hasMember(invitedPlayerId));
}