#pragma once

#include <cstdint>
#include <common/entity/Guid.h>
#include "common/time/Timestamp.h"

namespace Guild {
    class LogEvent {
    public:
        enum class Type {
            INVITATION = 1,
            NEW_MEMBER = 2,
            PROMOTION = 3,
            DEMOTION = 4,
            KICK = 5,
            MEMBER_LEFT = 6,
        };

        /**
         * Type : INVITATION
         * Type : KICK
         */
        LogEvent(Type type_, Guid& inviterOrKicker, Guid& invitedOrKicked);

        /**
         * Type : NEW_MEMBER
         * Type : MEMBER_LEFT
         */
        LogEvent(Type type_, Guid& playerGuid);

        /**
         * Type : PROMOTION
         * Type : DEMOTION
         */
        LogEvent(Type type_, Guid& promoterOrDemoter, Guid& promotedOrDemoted, uint8 newRank);


        ~LogEvent();

        //void setTimestamp(Timestamp& timestamp_);

        Type type;
        Guid& playerGuid1;
        Guid& playerGuid2;
        uint8 newRank;

        //Timestamp& timestamp;
    };
}