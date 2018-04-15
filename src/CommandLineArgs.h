#pragma once
#include <string>

struct CommandLineArgs {
    int argc;
    const char** argv;

    CommandLineArgs(int argc_, const char** argv_);

    std::string get(std::string name);
};
