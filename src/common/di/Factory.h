#pragma once

#include <boost/di/extension/injections/factory.hpp>

/**
 * This was initially supposed to be an interface to avoid coupling to Boost, but it was too complicated and added a lot of boiletplate code for each Factory.
 * Still looking for a cleaner way to do this.
 */
template<class T, class...TArgs>
using Factory = boost::di::extension::ifactory<T, TArgs...>;
