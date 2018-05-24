#include "InviteCommand.h"

namespace Guild {
    InviteCommand::InviteCommand(Guid &playerId_, Invite &invite_) : Command(playerId), invite(invite_) {
    }

    void InviteCommand::run(InviteCommandArgs args) {

    }
}