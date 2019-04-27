#pragma once

#define BOOST_DI_CFG_DIAGNOSTICS_LEVEL 2
#include <common/network/boost/BoostTcpServer.h>
#include <common/network/boost/BoostTcpClient.h>
#include <common/network/NetworkConnectionsMap.h>
#include <common/uuid/BoostUUIDFactory.h>
#include "boost/di/extension/bindings/constructor_bindings.hpp"
#include <common/app/Resources.h>
#include <common/app/RealSettingsRepository.h>
#include <common/network/NetworkInterface.h>
#include <common/network/boost/BoostTcpConnection.h>
#include <common/uuid/UUID.h>

auto AppModule = [] {
    return boost::di::make_injector(
            boost::di::bind<NetworkServer>.to<BoostTcpServer>(),
            boost::di::bind<NetworkClient>.to<BoostTcpClient>(),
            boost::di::bind<Launchable>.to<NetworkInterface>(),
            boost::di::bind<Loadable>.to<Resources>(),
            boost::di::bind<SettingsRepository>.to<RealSettingsRepository>(),
            boost::di::bind<NetworkConnectionRepository>.to<NetworkConnectionsMap>(),
            boost::di::bind<boost::asio::ip::tcp::socket>.to(boost::di::extension::constructor<boost::asio::io_context&>()),
            boost::di::bind<SocketFactory>.to(boost::di::extension::factory<boost::asio::ip::tcp::socket>{}),
            boost::di::bind<ConnectionFactory>.to(boost::di::extension::factory<BoostTcpConnection>{}),
            boost::di::bind<UUIDFactory>.to<BoostUUIDFactory>()
    );
};