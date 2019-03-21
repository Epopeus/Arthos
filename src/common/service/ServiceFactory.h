#pragma once

#include <boost/di.hpp>
#include <common/network/BoostTcpServer.h>
#include <common/network/BoostTcpClient.h>
#include "Service.h"

class ServiceFactory {
public:
    template<typename T>
    T create(int argc, const char** argv) {
        const auto injector = boost::di::make_injector(
        boost::di::bind<NetworkServer>.template to<BoostTcpServer>(),
        boost::di::bind<NetworkClient>.template to<BoostTcpClient>()
        );

        return injector.template create<T>();
    }
};

