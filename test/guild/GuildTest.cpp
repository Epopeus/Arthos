#include <gtest/gtest.h>
#include "game/guild/Roster.h"
#include "game/guild/Invitation.h"
#include "game/Faction.h"
#include "game/guild/Log.h"

class GuildTest : public ::testing::Test {
protected:
    virtual void SetUp() {

    }
};

TEST(InvitationTest, AddsMemberToRosterWhenInvitationIsAccepted) {
    Guid invitedPlayerId = Guid(123);
    Roster invitedPlayerCurrentRoster = Roster();
    Faction invitedPlayerFaction = Faction(0);

    Roster invitingPlayerRoster = Roster();
    Faction invitingPlayerFaction = Faction(0);

    Invitation invitation = Invitation(invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerCurrentRoster, invitedPlayerFaction);

    invitation.accept();

    ASSERT_TRUE(invitingPlayerRoster.hasMember(invitedPlayerId));
}

TEST(InvitationTest, LogsWhenInvitationSucceded) {
    Guid invitedPlayerId = Guid(123);
    Roster invitedPlayerCurrentRoster = Roster();
    Faction invitedPlayerFaction = Faction(0);

    Roster invitingPlayerRoster = Roster();
    Faction invitingPlayerFaction = Faction(0);

    Log log = Log();

    Invitation invitation = Invitation(invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerCurrentRoster, invitedPlayerFaction);

    invitation.accept();

}

TEST(InvitationTest, InformsRosterWhenInvitationSucceded) {

}

TEST(InvitationTest, FailsWhenPlayerIsMember) {
    Guid invitedPlayerId = Guid(123);
    Roster invitedPlayerCurrentRoster = Roster();
    Faction invitedPlayerFaction = Faction(0);

    Roster invitingPlayerRoster = Roster();
    invitingPlayerRoster.add(invitedPlayerId);
    Faction invitingPlayerFaction = Faction(0);

    Invitation invitation = Invitation(invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerCurrentRoster, invitedPlayerFaction);

    invitation.accept();

    ASSERT_EQ(1, invitingPlayerRoster.getNumberOfMembers());
}

TEST(InvitationTest, FailsWhenPlayerIsInOtherGuild) {
    Guid invitedPlayerId = Guid(123);
    Roster invitedPlayerCurrentRoster = Roster();
    invitedPlayerCurrentRoster.add(invitedPlayerId);
    Faction invitedPlayerFaction = Faction(0);

    Roster invitingPlayerRoster = Roster();
    Faction invitingPlayerFaction = Faction(0);

    Invitation invitation = Invitation(invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerCurrentRoster, invitedPlayerFaction);

    invitation.accept();

    ASSERT_FALSE(invitingPlayerRoster.hasMember(invitedPlayerId));
}

TEST(InvitationTest, FailsWhenPlayerBelongsToOtherFaction) {
    Guid invitedPlayerId = Guid(123);
    Roster invitedPlayerCurrentRoster = Roster();
    Faction invitedPlayerFaction = Faction(1);

    Roster invitingPlayerRoster = Roster();
    Faction invitingPlayerFaction = Faction(0);

    Invitation invitation = Invitation(invitingPlayerRoster, invitingPlayerFaction, invitedPlayerId, invitedPlayerCurrentRoster, invitedPlayerFaction);

    invitation.accept();

    ASSERT_FALSE(invitingPlayerRoster.hasMember(invitedPlayerId));
}