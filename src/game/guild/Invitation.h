#pragma once


#include "Guild.h"
#include "game/Guid.h"
#include "Roster.h"
#include "game/Faction.h"
#include "game/guild/log/Log.h"

class Invitation {
public:
    Invitation(Guid& invitingPlayerId_, Roster& invitingPlayerRoster_, Faction& invitingPlayerFaction_, Guid& invitedPlayerId_, Roster& invitedPlayerCurrentRoster_, Faction& invitedPlayerFaction_, Log& log_);

    ~Invitation();

    void accept();
    void decline();

private:
    Guid& invitingPlayerId;
    Roster& invitingPlayerRoster;
    Faction& invitingPlayerFaction;

    Guid& invitedPlayerId;
    Roster& invitedPlayerCurrentRoster;
    Faction& invitedPlayerFaction;

    Log& log;
};