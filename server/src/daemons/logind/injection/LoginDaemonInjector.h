#pragma once
#include "LoginDaemonScope.h"
#include "../LoginDaemon.h"
#include "../BoostTcpServer.h"

class LoginDaemonInjector {
public:
    static BoostTcpServer injectBoostTcpServer() {
        return BoostTcpServer();
    }

    static LoginDaemon injectLoginDaemon(LoginDaemonScope scope) {
        return LoginDaemon(injectBoostTcpServer());
    }
};

