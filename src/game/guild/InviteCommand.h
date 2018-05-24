#pragma once


#include <common/entity/Guid.h>
#include <common/command/Command.h>

struct InviteCommandArgs {
    const char* invitedCharName;
};

class InviteCommand : public Command {
public:
    InviteCommand(Guid& playerId);

    void run(InviteCommandArgs args);
};

