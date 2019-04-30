#pragma once

#define BOOST_DI_CFG_DIAGNOSTICS_LEVEL 2
#include <common/uuid/BoostUUIDFactory.h>
#include "boost/di/extension/bindings/constructor_bindings.hpp"
#include <common/app/Resources.h>
#include <common/app/RealSettingsRepository.h>
#include <common/network/NetworkModule.h>
#include <common/network/boost/BoostTcpConnection.h>
#include <common/uuid/UUID.h>
#include <common/network/NetworkInterface.h>
#include <common/network/boost/BoostNetworkInterface.h>
#include <common/network/boost/BoostNetworkConnectionRepository.h>

auto AppModule = [] {
    return boost::di::make_injector(
            boost::di::bind<NetworkInterface>.to<BoostNetworkInterface>(),
            boost::di::bind<Launchable>.to<NetworkModule>(),
            boost::di::bind<Loadable>.to<Resources>(),
            boost::di::bind<SettingsRepository>.to<RealSettingsRepository>(),
            boost::di::bind<NetworkConnectionRepository>.to<BoostNetworkConnectionRepository>(),
            boost::di::bind<boost::asio::ip::tcp::socket>.to(boost::di::extension::constructor<boost::asio::io_context&>()),
            boost::di::bind<SocketFactory>.to(boost::di::extension::factory<boost::asio::ip::tcp::socket>{}),
            boost::di::bind<ConnectionFactory>.to(boost::di::extension::factory<BoostTcpConnection>{}),
            boost::di::bind<UUIDFactory>.to<BoostUUIDFactory>()
    );
};