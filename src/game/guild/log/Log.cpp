#include "Log.h"
#include "LogEvent.h"
#include <memory>

namespace Guild {
    Log::Log(Clock &clock_) : clock(clock_) {
    }

    Log::~Log() {
    }

    const std::vector<std::unique_ptr<LogEvent>>& Log::getEvents() const {
        return events;
    }

    void Log::logEvent(std::unique_ptr<LogEvent> event) {
        events.push_back(std::move(event));
    }
}