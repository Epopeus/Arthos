#include "LoginDaemonScope.h"

LoginDaemonScope::LoginDaemonScope(int argc, char** argv) : argc(argc), argv(argv) {
}

int LoginDaemonScope::getArgc() const {
    return argc;
}

char *const *LoginDaemonScope::getArgv() const {
    return argv;
}
