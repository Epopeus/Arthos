#include <boost/di.hpp>
#include <common/service/CommandLineArgs.h>
#include <common/network/BoostTcpServer.h>
#include "AuthService.h"

int main(int argc, const char** argv) {
    // TODO : we have to use this because Boost.DI doesn't allow easy char** binding
    CommandLineArgs args = CommandLineArgs(argc, argv);

    const auto injector = boost::di::make_injector(
            boost::di::bind<CommandLineArgs>.to(args),
            boost::di::bind<TcpServer>.to<BoostTcpServer>()
    );

    AuthService authService = injector.create<AuthService>();

    authService.run();
}