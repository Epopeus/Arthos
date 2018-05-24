#pragma once

#include "common/entity/Guid.h"
#include "common/entity/Name.h"
#include "common/network/PacketDeliveryServer.h"
#include "game/Faction.h"
#include "Roster.h"
#include "log/Log.h"

namespace Guild {
    struct InvitingCharacter {
        Guid& id;
        Faction& faction;
        Roster& roster;

        InvitingCharacter(Guid& id_, Faction& faction_, Roster& roster_):id(id_), faction(faction_), roster(roster_) {

        }
    };

    struct InvitedCharacter : public InvitingCharacter {
        Name &name;

        InvitedCharacter(Guid &id_, Faction &faction_, Roster &roster_, Name &name_) : InvitingCharacter(id_, faction_, roster_), name(name_) {

        }
    };

    class Invite {
    public:
        Invite(InvitedCharacter& invitedCharacter_, Log &log_, PacketDeliveryServer &packetDeliveryServer_);

        ~Invite();

        void accept();
        void setInvitingCharacter(std::unique_ptr<InvitingCharacter> invitingCharacter_);
    private:
        std::unique_ptr<InvitingCharacter> invitingCharacter;
        InvitedCharacter& invitedCharacter;

        Log &log;

        PacketDeliveryServer &packetDeliveryServer;
    };
}

