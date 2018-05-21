#include "Log.h"

namespace Guild {
    Log::Log(Clock &clock_) : clock(clock_) {
    }

    Log::~Log() {
    }

    const std::vector<LogEvent> &Log::getEvents() const {
        return events;
    }

    void Log::logEvent(LogEvent event) {
        events.push_back(event);
    }
}