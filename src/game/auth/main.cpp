#include <boost/di.hpp>
#include "BoostTcpServer.h"
#include "AuthService.h"

int main(int argc, char** argv) {

    const auto injector = boost::di::make_injector(
            boost::di::bind<TcpServer>.to<BoostTcpServer>()
    );

    AuthService authService = injector.create<AuthService>();

    authService.run();
}