#include "Log.h"

Log::Log(Clock& clock_):clock(clock_) {
}

Log::~Log() {
}

const std::vector<Event>& Log::getEvents() const {
    return events;
}

void Log::logEvent(Event event) {
    events.push_back(event);
}