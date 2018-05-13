#include <gtest/gtest.h>
#include "game/guild/Invitation.h"

class GuildInvitationTest : public ::testing::Test {
public:
    GuildInvitationTest():
        invitedPlayerId(Guid(123)),
        invitedPlayerCurrentRoster(Roster()),
        invitedPlayerFaction(Faction(0)),

        invitingPlayerId(Guid(456)),
        invitingPlayerRoster(Roster()),
        invitingPlayerFaction(Faction(0)),

        clock(Clock()),
        log(Log(clock)),

        invitation(Invitation(invitingPlayerId, invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerCurrentRoster, invitedPlayerFaction, log))
        {

        }

    Guid invitedPlayerId;
    Roster invitedPlayerCurrentRoster;
    Faction invitedPlayerFaction;

    Guid invitingPlayerId;
    Roster invitingPlayerRoster;
    Faction invitingPlayerFaction;

    Clock clock;
    Log log;

    Invitation invitation;
};

TEST_F(GuildInvitationTest, AddsMemberToRosterWhenInvitationIsAccepted) {
    invitation.accept();

    ASSERT_TRUE(invitingPlayerRoster.hasMember(invitedPlayerId));
}

TEST_F(GuildInvitationTest, LogsWhenInvitationSucceded) {
    invitation.accept();

    const Event& event = log.getEvents().at(0);
    ASSERT_EQ(Type::INVITED_PLAYER, event.type);
    ASSERT_EQ(invitingPlayerId, event.playerGuid1);
    ASSERT_EQ(invitedPlayerId, event.playerGuid2);
}

TEST_F(GuildInvitationTest, InformsRosterWhenInvitationSucceded) {

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