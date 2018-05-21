#include <gtest/gtest.h>
#include "game/guild/Invitation.h"
#include "game/guild/EventPacket.h"

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
namespace Guild {
    class InvitationTest : public ::testing::Test {
    public:
        InvitationTest() :
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

                invitation(Invitation(invitingPlayerId, invitingPlayerRoster, invitingPlayerFaction,
                                             invitedPlayerId, invitedPlayerName, invitedPlayerCurrentRoster,
                                             invitedPlayerFaction, log, packetDeliveryServer)) {

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

    TEST_F(InvitationTest, TestBinary) {

    }

    TEST_F(InvitationTest, AddsMemberToRosterWhenInvitationIsAccepted) {
        invitation.accept();

        ASSERT_TRUE(invitingPlayerRoster.hasMember(invitedPlayerId));
    }

    TEST_F(InvitationTest, LogsWhenInvitationSucceded) {
        invitation.accept();

        LogEvent *event = (LogEvent *) log.getEvents().at(0).get();
        ASSERT_EQ(LogEvent::Type::NEW_MEMBER, event->type);
        ASSERT_EQ(invitedPlayerId, event->playerGuid1);
    }

    TEST_F(InvitationTest, InformsRosterWhenInvitationSucceded) {
        invitation.accept();

        EventPacket *packet = (EventPacket *) packetDeliveryServer.sentPackets.at(0).get();

        ASSERT_EQ(EventPacket::Type::NEW_MEMBER, packet->type);
        ASSERT_EQ(invitedPlayerId, *packet->playerGuid);
        ASSERT_EQ(invitedPlayerName, packet->miscStrings.at(0));
    }

    TEST_F(InvitationTest, FailsWhenPlayerIsMember) {
        invitingPlayerRoster.add(invitedPlayerId);

        invitation.accept();

        ASSERT_EQ(1, invitingPlayerRoster.getNumberOfMembers());
    }

    TEST_F(InvitationTest, FailsWhenPlayerIsInOtherGuild) {
        invitedPlayerCurrentRoster.add(invitedPlayerId);

        invitation.accept();

        ASSERT_FALSE(invitingPlayerRoster.hasMember(invitedPlayerId));
    }

    TEST_F(InvitationTest, FailsWhenPlayerBelongsToOtherFaction) {
        invitedPlayerFaction = Faction(1);

        invitation.accept();

        ASSERT_FALSE(invitingPlayerRoster.hasMember(invitedPlayerId));
    }
}