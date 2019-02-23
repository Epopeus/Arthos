#pragma once

#include <boost/di.hpp>
#include "CommandLineArgs.h"
#include <common/network/BoostTcpServer.h>
#include "Service.h"

class ServiceFactory {
public:
    ServiceFactory();
    ~ServiceFactory();

    template<typename T>
    T create(int argc, const char** argv) {
        // TODO : we have to use this because Boost.DI doesn't allow easy char** binding
        CommandLineArgs args = CommandLineArgs(argc, argv);

        const auto injector = boost::di::make_injector(
        boost::di::bind<CommandLineArgs>.to(args),
        boost::di::bind<TcpServer>.template to<BoostTcpServer>()
        );

        return injector.template create<T>();
    }
};

