#pragma once

#include "common/command/Command.h"

class AcceptInviteCommand : public Command {
public:
    AcceptInviteCommand(Guid& playerId);

    void run();
};

