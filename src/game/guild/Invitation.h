#pragma once


#include "Guild.h"
#include "common/entity/Guid.h"
#include "Roster.h"
#include "game/Faction.h"
#include "game/guild/log/Log.h"
#include "common/entity/Name.h"

class Invitation {
public:
    Invitation(Guid& invitingPlayerId_, Roster& invitingPlayerRoster_, Faction& invitingPlayerFaction_, Guid& invitedPlayerId_, Name& invitedPlayerName, Roster& invitedPlayerCurrentRoster_, Faction& invitedPlayerFaction_, Log& log_, PacketDeliveryServer& packetDeliveryServer_);

    ~Invitation();

    void accept();
    void decline();

private:
    Guid& invitingPlayerId;
    Roster& invitingPlayerRoster;
    Faction& invitingPlayerFaction;

    Guid& invitedPlayerId;
    Name& invitedPlayerName;
    Roster& invitedPlayerCurrentRoster;
    Faction& invitedPlayerFaction;

    Log& log;

    PacketDeliveryServer& packetDeliveryServer;
};