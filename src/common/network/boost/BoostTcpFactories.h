#pragma once

#include <boost/asio.hpp>
#include <common/network/NetworkConnection.h>
#include <common/di/Factory.h>

using SocketFactory = Factory<boost::asio::ip::tcp::socket>;
using ConnectionFactory = Factory<NetworkConnection&, boost::asio::ip::tcp::socket&>;