#include "Invitation.h"

Invitation::Invitation(Guid& invitingPlayerId_, Roster& invitingPlayerRoster_, Faction& invitingPlayerFaction_, Guid& invitedPlayerId_, Roster& invitedPlayerCurrentRoster_, Faction& invitedPlayerFaction_, Log& log_):
        invitingPlayerId(invitingPlayerId_), invitingPlayerRoster(invitingPlayerRoster_), invitingPlayerFaction(invitingPlayerFaction_), invitedPlayerId(invitedPlayerId_), invitedPlayerCurrentRoster(invitedPlayerCurrentRoster_), invitedPlayerFaction(invitedPlayerFaction_), log(log_) {
}

Invitation::~Invitation() {
}

void Invitation::accept() {
    if (invitedPlayerCurrentRoster.hasMember(invitedPlayerId))
        return;

    if (invitedPlayerFaction != invitingPlayerFaction)
        return;

    invitingPlayerRoster.add(invitedPlayerId);

    log.logEvent(Event(Type::INVITED_PLAYER, invitingPlayerId, invitedPlayerId));
}

void Invitation::decline() {

}