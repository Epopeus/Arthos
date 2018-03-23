#pragma once

struct CommandLineArgs {
    int argc;
    char** argv;

    CommandLineArgs(int argc_, char** argv_):argc(argc_),argv(argv_) {
    }
};
