#pragma once

#include "common/entity/Guid.h"
#include "common/entity/Name.h"
#include "common/network/PacketDeliveryServer.h"
#include "game/Faction.h"
#include "Roster.h"
#include "log/Log.h"

namespace Guild {
    class Invitation {
    public:
        Invitation(Guid &invitingPlayerId_, Roster &invitingPlayerRoster_, Faction &invitingPlayerFaction_,
                   Guid &invitedPlayerId_, Name &invitedPlayerName, Roster &invitedPlayerCurrentRoster_,
                   Faction &invitedPlayerFaction_, Log &log_, PacketDeliveryServer &packetDeliveryServer_);

        ~Invitation();

        void accept();
    private:
        Guid &invitingPlayerId;
        Roster &invitingPlayerRoster;
        Faction &invitingPlayerFaction;

        Guid &invitedPlayerId;
        Name &invitedPlayerName;
        Roster &invitedPlayerCurrentRoster;
        Faction &invitedPlayerFaction;

        Log &log;

        PacketDeliveryServer &packetDeliveryServer;
    };
}

