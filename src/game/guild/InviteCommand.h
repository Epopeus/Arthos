#pragma once


#include <common/entity/Guid.h>
#include <common/command/GameClientCommand.h>
#include <common/entity/EntityManager.h>

namespace Guild {
    class InviteCommand : public Command {
    public:
        InviteCommand(Guid &characterId_, EntityManager &entityManager_);

        void run(CommandArgs& args) override;
    private:
        EntityManager& entityManager;
    };
}

