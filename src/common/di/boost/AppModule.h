#pragma once

#define BOOST_DI_CFG_DIAGNOSTICS_LEVEL 2
#include <boost/di.hpp>
#include <common/app/BoostSettingsRepository.h>
#include <common/network/boost/BoostNetworkInterface.h>
#include <boost/di/extension/bindings/constructor_bindings.hpp>
#include <common/di/boost/BoostFactory.h>
#include <common/network/boost/BoostNetworkConnectionRepository.h>
#include <common/uuid/BoostUUIDFactory.h>

using namespace boost;

auto AppModule = [](int argc, const char** argv) {
    return make_injector(
            di::bind<SettingsRepository>.to<BoostSettingsRepository>(),

               di::bind<NetworkInterface>.to<BoostNetworkInterface>(),
                   di::bind<boost::asio::ip::tcp::socket>.to(di::extension::constructor<boost::asio::io_context&>()),
                   di::bind<SocketFactory>.to<BoostFactory<boost::asio::ip::tcp::socket>>(),
                   di::bind<ConnectionFactory>.to<BoostFactory<NetworkConnection&, boost::asio::ip::tcp::socket&>>(),

                di::bind<UUIDFactory>.to<BoostUUIDFactory>(),

                di::bind<NetworkConnectionEntryFactory>.to<BoostFactory<NetworkConnectionEntry, NetworkConnectionId, NetworkConnection&, NetworkConnectionType>>(),
                    di::bind<ReceivedBytesQueue>.in(di::unique),

                di::bind<NetworkConnectionRepository>.to<BoostNetworkConnectionRepository>()

    );
};