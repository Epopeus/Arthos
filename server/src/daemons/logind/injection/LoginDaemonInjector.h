#pragma once
#include "LoginDaemonScope.h"
#include "../LoginDaemon.h"
#include "../BoostTcpServer.h"

class LoginDaemonInjector {
public:
    static LoginDaemon injectLoginDaemon(LoginDaemonScope scope) {
        BoostTcpServer server{};
        return LoginDaemon(server);
    }
};

