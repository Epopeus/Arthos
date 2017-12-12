#include <boost/di.hpp>
#include "LoginDaemon.h"
#include "BoostTcpServer.h"

int main(int argc, char** argv) {

    const auto injector = boost::di::make_injector(
            boost::di::bind<TcpServer>.to<BoostTcpServer>()
    );

    LoginDaemon loginDaemon = injector.create<LoginDaemon>();

    loginDaemon.run();
}