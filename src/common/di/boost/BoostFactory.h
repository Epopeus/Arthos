#pragma once

#define BOOST_DI_CFG_DIAGNOSTICS_LEVEL 2
#include <common/di/Factory.h>
#include <typeindex>
#include <boost/di.hpp>
#include <functional>
#include "ServiceModule.h"
#include <common/app/App.h>
#include <tuple>
#include <any>

/*
 * TODO : check T at compile time : static assert, enable_if, ...
 */
template<class T, class...TArgs>
class BoostFactory : public Factory<T, TArgs...> {
public:
    T create(TArgs... args) override {
        boost::di::injector<T> injector = CLASSES_MODULE_MAP.at(typeid(T))();

        return injector.template create<T>();
    }

private:
    const static inline std::unordered_map<std::type_index, std::function<void()>> CLASSES_MODULE_MAP = {
            { typeid(App), ServiceModule }
    };
};
