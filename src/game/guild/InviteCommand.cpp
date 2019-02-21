#include "InviteCommand.h"
#include "GuildComponent.h"

namespace Guild {
    InviteCommand::InviteCommand(Guid &characterId_, EntityManager &entityManager_) : Command(characterId_), entityManager(entityManager_) {
    }

    void InviteCommand::run(CommandArgs& args) {
        /*
         * Checks :
         * - invited exists
         * - inviting is in guild
         * - inviting has invite rights
         * - invited does not ignore inviting
         * - invited is in same faction
         * - invited isn't in guild already
         * - invited isn't invited already
         */
        /*const std::string invitedCharName(_invitedCharName); // TODO : normalize name
        auto result = entityManager.findEntityId(invitedCharName);

        if (!result)
            return; // TODO : return opcode


        GuildComponent& guildComponent = entityManager.getComponent<GuildComponent>(result.value()).

    
        Guild* guild = sGuildMgr.GetGuildById(GetPlayer()->GetGuildId());
        if (!guild)
        {
            SendGuildCommandResult(GUILD_CREATE_S, "", ERR_GUILD_PLAYER_NOT_IN_GUILD);
            return;
        }

        // OK result but not send invite
        if (player->GetSocial()->HasIgnore(GetPlayer()->GetObjectGuid()))
            return;

        // not let enemies sign guild charter
        if (!sWorld.getConfig(CONFIG_BOOL_ALLOW_TWO_SIDE_INTERACTION_GUILD) && player->GetTeam() != GetPlayer()->GetTeam())
        {
            SendGuildCommandResult(GUILD_INVITE_S, Invitedname, ERR_GUILD_NOT_ALLIED);
            return;
        }

        if (player->GetGuildId())
        {
            plname = player->GetName();
            SendGuildCommandResult(GUILD_INVITE_S, plname, ERR_ALREADY_IN_GUILD_S);
            return;
        }

        if (player->GetGuildIdInvited())
        {
            plname = player->GetName();
            SendGuildCommandResult(GUILD_INVITE_S, plname, ERR_ALREADY_INVITED_TO_GUILD_S);
            return;
        }

        if (!guild->HasRankRight(GetPlayer()->GetRank(), GR_RIGHT_INVITE))
        {
            SendGuildCommandResult(GUILD_INVITE_S, "", ERR_GUILD_PERMISSIONS);
            return;
        }

        DEBUG_LOG("Player %s Invited %s to Join his Guild", GetPlayer()->GetName(), Invitedname.c_str());

        player->SetGuildIdInvited(GetPlayer()->GetGuildId());
        // Put record into guildlog
        guild->LogGuildEvent(GUILD_EVENT_LOG_INVITE_PLAYER, GetPlayer()->GetObjectGuid(), player->GetObjectGuid());

        WorldPacket data(SMSG_GUILD_INVITE, (8 + 10));          // guess size
        data << GetPlayer()->GetName();
        data << guild->GetName();
        player->GetSession()->SendPacket(data);
        */
    }
}