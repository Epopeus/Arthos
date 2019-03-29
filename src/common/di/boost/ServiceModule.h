#pragma once

#define BOOST_DI_CFG_DIAGNOSTICS_LEVEL 2
#include <common/network/BoostTcpServer.h>
#include <common/network/BoostTcpClient.h>
#include <common/network/NetworkConnectionsMap.h>
#include <common/uuid/BoostUUIDFactory.h>
#include "boost/di/extension/bindings/constructor_bindings.hpp"
#include <common/service/ServiceResources.h>
#include <common/service/RealServiceSettingsRepository.h>
#include <common/network/NetworkInterface.h>
#include <common/network/BoostTcpConnection.h>
#include <common/uuid/UUID.h>

auto ServiceModule = [] {
    return boost::di::make_injector(
            boost::di::bind<NetworkServer>.to<BoostTcpServer>(),
            boost::di::bind<NetworkClient>.to<BoostTcpClient>(),
            boost::di::bind<Launchable>.to<NetworkInterface>(),
            boost::di::bind<Loadable>.to<ServiceResources>(),
            boost::di::bind<ServiceSettingsRepository>.to<RealServiceSettingsRepository>(),
            boost::di::bind<NetworkConnections>.to<NetworkConnectionsMap>(),
            boost::di::bind<boost::asio::ip::tcp::socket>.to(boost::di::extension::constructor<boost::asio::io_context&>()),
            boost::di::bind<SocketFactory>.to(boost::di::extension::factory<boost::asio::ip::tcp::socket>{}),
            boost::di::bind<ConnectionFactory>.to(boost::di::extension::factory<BoostTcpConnection>{}),
            boost::di::bind<UUIDFactory>.to<BoostUUIDFactory>()
    );
};