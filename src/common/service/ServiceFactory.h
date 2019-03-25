#pragma once

#include "Service.h"

class ServiceFactory {
public:
    Service create(int argc, const char** argv);
};

