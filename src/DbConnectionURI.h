#pragma once
#include "CommandLineArgs.h"

class DbConnectionURI {
public:
    DbConnectionURI();

    DbConnectionURI(CommandLineArgs &commandLineArgs);

    ~DbConnectionURI();

private:
    CommandLineArgs& commandLineArgs;
};

