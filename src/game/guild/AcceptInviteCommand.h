#pragma once

#include "common/command/GameClientCommand.h"

class AcceptInviteCommand : public Command {
public:
    AcceptInviteCommand(Guid& characterId);

    void run();
};

