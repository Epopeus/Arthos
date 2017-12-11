#include <iostream>
#include "injection/LoginDaemonScope.h"
#include "LoginDaemon.h"
#include "injection/LoginDaemonInjector.h"

int main(int argc, char** argv) {
    LoginDaemonScope scope = LoginDaemonScope(argc, argv);
    LoginDaemon loginDaemon = LoginDaemonInjector::injectLoginDaemon(scope);
    loginDaemon.run();
}