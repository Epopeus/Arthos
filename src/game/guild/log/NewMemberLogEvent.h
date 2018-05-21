#pragma once

#include "LogEvent.h"

namespace Guild {
    class NewMemberLogEvent : public LogEvent {
    public:
        NewMemberLogEvent(Guid& newPlayerGuid);
    };
}

