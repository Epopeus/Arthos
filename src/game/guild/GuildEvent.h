#pragma once

#include "common/network/ServerPacket.h"
#include "common/entity/Guid.h"
#include <string>
#include <array>
#include <boost/shared_ptr.hpp>
#include "common/entity/Name.h"

class GuildEvent : public ServerPacket {
public:

    enum class Type {
        PROMOTION               = 0x00,
        DEMOTION                = 0x01,
        MOTD                    = 0x02,
        NEW_MEMBER              = 0x03,
        MEMBER_LEFT             = 0x04,
        KICK                    = 0x05,
        TODO                    = 0x06,
        NEW_LEADER              = 0x07,
        DISBAND                 = 0x08,
        TABARD_CHANGED          = 0x09,
        UNK1                    = 0x0A,
        UNK2                    = 0x0B,
        MEMBER_LOGIN            = 0x0C,
        MEMBER_LOGOUT           = 0x0D,
    };

    /**
     * Type::DISBAND
     */
    GuildEvent();

    /**
     * Type::MOTD
     */
    GuildEvent(std::string& motd);

    /**
     * Type::PROMOTION
     * Type::DEMOTION
     */
    GuildEvent(Type type_, Name& promoterOrDemoterName, Name& promotedOrDemotedName, std::string& newRankName);


    /**
     * Type::NEW_MEMBER
     * Type::MEMBER_LEFT
     * Type::MEMBER_LOGIN
     * Type::MEMBER_LOGOUT
     */
    GuildEvent(Type type_, Guid& playerGuid_, Name& playerName);

    /**
     * Type::KICK
     * Type::NEW_LEADER
     */
    GuildEvent(Type type_, Name& kickerOrOldLeaderName, Name& kickedOrNewLeaderName);

    ~GuildEvent();

    Type type;
    Guid* playerGuid;
    std::vector<std::string> miscStrings;

private:
    GuildEvent(Type type_, Guid* playerGuid_, std::vector<std::string> miscStrings_);
};