#include "NewMemberLogEvent.h"

namespace Guild {
    NewMemberLogEvent::NewMemberLogEvent(Guid& newPlayerGuid):LogEvent(LogEvent::Type::NEW_MEMBER, newPlayerGuid) {
    }
}