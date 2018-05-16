#pragma once

#include <cstdint>
#include <game/Guid.h>
#include "common/time/Timestamp.h"

enum class Type {
    INVITED_PLAYER      = 1,
    JOINED_GUILD        = 2,
    PROMOTED_PLAYER     = 3,
    DEMOTED_PLAYER      = 4,
    UNINVITED_PLAYER    = 5,
    LEFT_GUILD          = 6,
};

class Event {
public:
    Event(Type type_, Guid& playerGuid1_, Guid& playerGuid2_);
    ~Event();

    //void setTimestamp(Timestamp& timestamp_);

    Type type;
    Guid& playerGuid1;
    Guid& playerGuid2;
    //Timestamp& timestamp;
};