#pragma once


#include <common/entity/Guid.h>
#include <common/command/Command.h>
#include "Invite.h"

namespace Guild {
    struct InviteCommandArgs {
        const char *invitedCharName;

        InviteCommandArgs(const char *invitedCharName_) : invitedCharName(invitedCharName_) {
        }
    };

    class InviteCommand : public Command {
    public:
        InviteCommand(Guid &playerId_, Invite &invite_);

        void run(InviteCommandArgs args);
    private:
        Invite& invite;
    };
}

