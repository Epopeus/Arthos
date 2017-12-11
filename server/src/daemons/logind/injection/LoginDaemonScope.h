#pragma once


class LoginDaemonScope {
public:
    LoginDaemonScope(int argc, char** argv);

    int getArgc() const;

    char* const* getArgv() const;

private:
    int argc;
    char** argv;
};

