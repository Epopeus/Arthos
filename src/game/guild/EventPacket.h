#pragma once

#include <common/entity/Name.h>
#include <common/entity/Guid.h>
#include "common/network/ServerPacket.h"

namespace Guild {
    class EventPacket : public ServerPacket {
    public:

        enum class Type {
            PROMOTION = 0x00,
            DEMOTION = 0x01,
            MOTD = 0x02,
            NEW_MEMBER = 0x03,
            MEMBER_LEFT = 0x04,
            KICK = 0x05,
            TODO = 0x06,
            NEW_LEADER = 0x07,
            DISBAND = 0x08,
            TABARD_CHANGED = 0x09,
            UNK1 = 0x0A,
            UNK2 = 0x0B,
            MEMBER_LOGIN = 0x0C,
            MEMBER_LOGOUT = 0x0D,
        };

        /**
         * Type::DISBAND
         */
        EventPacket();

        /**
         * Type::MOTD
         */
        EventPacket(std::string &motd);

        /**
         * Type::PROMOTION
         * Type::DEMOTION
         */
        EventPacket(Type type_, Name &promoterOrDemoterName, Name &promotedOrDemotedName, std::string &newRankName);

        /**
         * Type::NEW_MEMBER
         * Type::MEMBER_LEFT
         * Type::MEMBER_LOGIN
         * Type::MEMBER_LOGOUT
         */
        EventPacket(Type type_, Guid &playerGuid_, Name &playerName);

        /**
         * Type::KICK
         * Type::NEW_LEADER
         */
        EventPacket(Type type_, Name &kickerOrOldLeaderName, Name &kickedOrNewLeaderName);

        ~EventPacket();

        Type type;
        Guid *playerGuid;
        std::vector<std::string> miscStrings;

    private:
        EventPacket(Type type_, Guid *playerGuid_, std::vector<std::string> miscStrings_);
    };
}