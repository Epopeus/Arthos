#pragma once

#include <cstdint>
#include <common/entity/Guid.h>
#include "common/time/Timestamp.h"

class Event {
public:
    enum class Type {
        INVITATION      = 1,
        NEW_MEMBER      = 2,
        PROMOTION       = 3,
        DEMOTION        = 4,
        KICK            = 5,
        MEMBER_LEFT     = 6,
    };
    Event(Type type_, Guid& playerGuid1_, Guid& playerGuid2_);
    ~Event();

    //void setTimestamp(Timestamp& timestamp_);

    Type type;
    Guid& playerGuid1;
    Guid& playerGuid2;
    //Timestamp& timestamp;
};