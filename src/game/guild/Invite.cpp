#include "Invite.h"
#include "EventPacket.h"
#include <functional>

namespace Guild {
    Invite::Invite(std::unique_ptr<InvitingCharacter> invitingCharacter_, std::unique_ptr<InvitedCharacter> invitedCharacter_, Log &log_, PacketDeliveryServer &packetDeliveryServer_) : invitingCharacter(std::move(invitingCharacter_)), invitedCharacter(std::move(invitedCharacter_)), log(log_), packetDeliveryServer(packetDeliveryServer_) {
    }

    Invite::~Invite() {
    }


    void Invite::accept() {
        if (invitedCharacter.get()->roster.hasMember(invitedCharacter.get()->id))
            return;

        if (invitedCharacter.get()->faction != invitingCharacter.get()->faction)
            return;

        invitingCharacter->roster.add(invitedCharacter.get()->id);

        log.logEvent(std::make_unique<LogEvent>(LogEvent::Type::NEW_MEMBER, invitedCharacter.get()->id));

        packetDeliveryServer.send(std::make_unique<EventPacket>(EventPacket::Type::NEW_MEMBER, invitedCharacter.get()->id, invitedCharacter.get()->name));
    }
}