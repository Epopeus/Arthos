#pragma once


#include "Guild.h"
#include "game/Guid.h"
#include "Roster.h"
#include "game/Faction.h"

class Invitation {
public:
    Invitation(Roster& invitingPlayerRoster_, Faction& invitingPlayerFaction_, Guid& invitedPlayerId_, Roster& invitedPlayerCurrentRoster_, Faction& invitedPlayerFaction_);

    ~Invitation();

    void accept();
    void decline();

private:
    Roster& invitingPlayerRoster;
    Faction& invitingPlayerFaction;

    Guid& invitedPlayerId;
    Roster& invitedPlayerCurrentRoster;
    Faction& invitedPlayerFaction;
};