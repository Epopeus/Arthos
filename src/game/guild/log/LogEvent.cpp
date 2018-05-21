#include "LogEvent.h"

namespace Guild {
    LogEvent::LogEvent(Type type_, Guid &playerGuid1_, Guid &playerGuid2_) : type(type_), playerGuid1(playerGuid1_),
                                                                             playerGuid2(playerGuid2_) {
    }

    LogEvent::~LogEvent() {
    }
}
