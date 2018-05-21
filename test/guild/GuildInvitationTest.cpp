#include <gtest/gtest.h>
#include <game/guild/GuildEvent.h>
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

class GuildInvitationTest : public ::testing::Test {
public:
    GuildInvitationTest():
            invitedPlayerId(Guid(123)),
            invitedPlayerName("Test"),
            invitedPlayerCurrentRoster(Roster()),
            invitedPlayerFaction(Faction(0)),

            invitingPlayerId(Guid(456)),
            invitingPlayerRoster(Roster()),
            invitingPlayerFaction(Faction(0)),

            clock(Clock()),
            log(Log(clock)),
            packetDeliveryServer(FakePacketDeliveryServer()),

            invitation(Invitation(invitingPlayerId, invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerName, invitedPlayerCurrentRoster, invitedPlayerFaction, log, packetDeliveryServer))
            {

            }

    Guid invitedPlayerId;
    Name invitedPlayerName;
    Roster invitedPlayerCurrentRoster;
    Faction invitedPlayerFaction;

    Guid invitingPlayerId;
    Roster invitingPlayerRoster;
    Faction invitingPlayerFaction;

    Clock clock;
    Log log;
    FakePacketDeliveryServer packetDeliveryServer;

    Invitation invitation;
};

TEST_F(GuildInvitationTest, InformsRosterWhenInvitationSucceded) {
    invitation.accept();

    GuildEvent* packet  = (GuildEvent*)packetDeliveryServer.sentPackets.at(0).get();

    ASSERT_EQ(GuildEvent::Type::NEW_MEMBER, packet->type);
    ASSERT_EQ(invitedPlayerId, *packet->playerGuid);
    ASSERT_EQ(invitedPlayerName, packet->miscStrings.at(0));
}

TEST_F(GuildInvitationTest, AddsMemberToRosterWhenInvitationIsAccepted) {
    invitation.accept();

    ASSERT_TRUE(invitingPlayerRoster.hasMember(invitedPlayerId));
}

TEST_F(GuildInvitationTest, LogsWhenInvitationSucceded) {
    invitation.accept();

    const Event& event = log.getEvents().at(0);
    ASSERT_EQ(Event::Type::NEW_MEMBER, event.type);
    ASSERT_EQ(invitingPlayerId, event.playerGuid1);
    ASSERT_EQ(invitedPlayerId, event.playerGuid2);
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