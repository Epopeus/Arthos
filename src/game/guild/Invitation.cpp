#include <common/network/PacketDeliveryServer.h>
#include "Invitation.h"
#include "GuildEvent.h"
Invitation::Invitation(Guid& invitingPlayerId_, Roster& invitingPlayerRoster_, Faction& invitingPlayerFaction_,
                       Guid& invitedPlayerId_, Name& invitedPlayerName_, Roster& invitedPlayerCurrentRoster_, Faction& invitedPlayerFaction_,
                       Log& log_, PacketDeliveryServer& packetDeliveryServer_):
        invitingPlayerId(invitingPlayerId_), invitingPlayerRoster(invitingPlayerRoster_), invitingPlayerFaction(invitingPlayerFaction_),
        invitedPlayerId(invitedPlayerId_), invitedPlayerName(invitedPlayerName_), invitedPlayerCurrentRoster(invitedPlayerCurrentRoster_), invitedPlayerFaction(invitedPlayerFaction_),
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

    log.logEvent(Event(Event::Type::NEW_MEMBER, invitingPlayerId, invitedPlayerId));

    packetDeliveryServer.send(std::make_unique<GuildEvent>(GuildEvent::Type::NEW_MEMBER, invitedPlayerId, invitedPlayerName));
}

void Invitation::decline() {

}