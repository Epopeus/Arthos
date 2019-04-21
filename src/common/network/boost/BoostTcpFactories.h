#pragma once

#include <boost/asio.hpp>
#include <boost/di.hpp>
#include <boost/di/extension/injections/factory.hpp>
#include "boost/di/extension/injections/lazy.hpp"
#include "common/network/NetworkConnection.h"

using SocketFactory = boost::di::extension::ifactory<boost::asio::ip::tcp::socket>;
using ConnectionFactory = boost::di::extension::ifactory<NetworkConnection, boost::asio::ip::tcp::socket&>;