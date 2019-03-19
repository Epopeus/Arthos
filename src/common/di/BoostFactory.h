#pragma once

#include "Factory.h"
#include <boost/di/extension/injections/factory.hpp>

template<class T, class... TArgs>
class BoostFactory : public Factory<T, TArgs...> {
public:
    BoostFactory(const boost::di::extension::ifactory<T, TArgs...>& factory_):factory(factory_) {

    }

    T create(TArgs&&... args) override {
        return factory.create(std::forward<TArgs>(args)...);
    }

private:
    const boost::di::extension::ifactory<T, TArgs...>& factory;
};