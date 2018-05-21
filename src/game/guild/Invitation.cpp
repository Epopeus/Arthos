#include "Invitation.h"
#include "EventPacket.h"
#include <functional>

namespace Guild {
    Invitation::Invitation(Guid &invitingPlayerId_, Roster &invitingPlayerRoster_, Faction &invitingPlayerFaction_,
                           Guid &invitedPlayerId_, Name &invitedPlayerName_, Roster &invitedPlayerCurrentRoster_,
                           Faction &invitedPlayerFaction_,
                           Log &log_, PacketDeliveryServer &packetDeliveryServer_) :
            invitingPlayerId(invitingPlayerId_), invitingPlayerRoster(invitingPlayerRoster_),
            invitingPlayerFaction(invitingPlayerFaction_),
            invitedPlayerId(invitedPlayerId_), invitedPlayerName(invitedPlayerName_),
            invitedPlayerCurrentRoster(invitedPlayerCurrentRoster_), invitedPlayerFaction(invitedPlayerFaction_),
            log(log_), packetDeliveryServer(packetDeliveryServer_) {
    }

    Invitation::~Invitation() {
    }

    void Invitation::accept() {
        if (invitedPlayerCurrentRoster.hasMember(invitedPlayerId))
            return;

        if (invitedPlayerFaction != invitingPlayerFaction)
            return;

        invitingPlayerRoster.add(invitedPlayerId);

        log.logEvent(std::make_unique<LogEvent>(LogEvent::Type::NEW_MEMBER, invitingPlayerId, invitedPlayerId));

        packetDeliveryServer.send(std::make_unique<EventPacket>(EventPacket::Type::NEW_MEMBER, invitedPlayerId, invitedPlayerName));
    }
}