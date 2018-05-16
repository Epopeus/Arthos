#pragma once

#include <vector>
#include "common/time/Clock.h"
#include "Event.h"

class Log {
public:
    Log(Clock& clock_);

    ~Log();

    const std::vector<Event>& getEvents() const;

    void logEvent(Event event);

private:
    Clock& clock;
    std::vector<Event> events;
};