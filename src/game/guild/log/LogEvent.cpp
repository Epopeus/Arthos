#include "LogEvent.h"

namespace Guild {
    LogEvent::LogEvent(Type type_, Guid& playerGuid1_) : type(type_), playerGuid1(playerGuid1_) {
    }
}
