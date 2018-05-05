#include "Invitation.h"

Invitation::Invitation(Roster& invitingPlayerRoster_, Faction& invitingPlayerFaction_, Guid& invitedPlayerId_, Roster& invitedPlayerCurrentRoster_, Faction& invitedPlayerFaction_):
        invitingPlayerRoster(invitingPlayerRoster_), invitingPlayerFaction(invitingPlayerFaction_), invitedPlayerId(invitedPlayerId_), invitedPlayerCurrentRoster(invitedPlayerCurrentRoster_), invitedPlayerFaction(invitedPlayerFaction_) {
}

Invitation::~Invitation() {
}

void Invitation::accept() {
    if (invitedPlayerCurrentRoster.hasMember(invitedPlayerId))
        return;

    if (invitedPlayerFaction != invitingPlayerFaction)
        return;

    invitingPlayerRoster.add(invitedPlayerId);
}

void Invitation::decline() {

}