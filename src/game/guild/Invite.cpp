#include "Invite.h"
#include "EventPacket.h"
#include <functional>

namespace Guild {
    Invite::Invite(InvitedCharacter& invitedCharacter_, Log &log_, PacketDeliveryServer &packetDeliveryServer_) : invitedCharacter(invitedCharacter_), log(log_), packetDeliveryServer(packetDeliveryServer_) {
    }

    Invite::~Invite() {
    }

    void Invite::setInvitingCharacter(std::unique_ptr<InvitingCharacter> invitingCharacter_) {
        invitingCharacter = std::move(invitingCharacter_);
    }

    void Invite::accept() {
        if (invitedCharacter.roster.hasMember(invitedCharacter.id))
            return;

        if (invitedCharacter.faction != invitingCharacter.get()->faction)
            return;

        invitingCharacter->roster.add(invitedCharacter.id);

        log.logEvent(std::make_unique<LogEvent>(LogEvent::Type::NEW_MEMBER, invitedCharacter.id));

        packetDeliveryServer.send(std::make_unique<EventPacket>(EventPacket::Type::NEW_MEMBER, invitedCharacter.id, invitedCharacter.name));
    }
}