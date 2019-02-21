#pragma once

#include "common/entity/Guid.h"
#include "common/entity/Name.h"
#include "common/network/PacketDeliveryServer.h"
#include "game/Faction.h"
#include "Roster.h"
#include "log/Log.h"

namespace Guild {
    struct InvitingCharacter {
        Guid id;
        Faction faction;

        InvitingCharacter(Guid id_, Faction faction_):id(id_), faction(faction_) {

        }
    };

    struct InvitedCharacter : public InvitingCharacter {
        Name name;

        InvitedCharacter(Guid id_, Faction faction_, Name name_) : InvitingCharacter(id_, faction_), name(name_) {

        }
    };

    class Invite {
    public:
        Invite(InvitedCharacter invitedCharacter_, Log &log_, PacketDeliveryServer &packetDeliveryServer_);

        ~Invite();

        void accept();
        void setInvitingCharacter(InvitingCharacter invitingCharacter_);
    private:
        std::optional<InvitingCharacter> invitingCharacter;
        InvitedCharacter invitedCharacter;

        Log &log;

        PacketDeliveryServer &packetDeliveryServer;
    };
}

