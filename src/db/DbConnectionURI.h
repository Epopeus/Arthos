#pragma once
#include "service/CommandLineArgs.h"

class DbConnectionURI {
public:
    DbConnectionURI();

    DbConnectionURI(CommandLineArgs &commandLineArgs);

    ~DbConnectionURI();

private:
    CommandLineArgs& commandLineArgs;
};

