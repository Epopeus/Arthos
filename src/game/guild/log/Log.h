#pragma once

#include "common/time/Clock.h"
#include <vector>
#include "LogEvent.h"
#include <memory>

namespace Guild {
    class Log {
    public:
        Log(Clock &clock_);

        ~Log();

        const std::vector<std::unique_ptr<LogEvent>>& getEvents() const;

        void logEvent(std::unique_ptr<LogEvent> event);

    private:
        Clock &clock;
        std::vector<std::unique_ptr<LogEvent>> events;
    };
}