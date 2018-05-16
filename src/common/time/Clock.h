#pragma once


#include "Timestamp.h"

class Clock {
public:
    Clock();

    ~Clock();

    Timestamp getTimestamp();
};