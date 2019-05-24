#pragma once

#define BOOST_DI_CFG_DIAGNOSTICS_LEVEL 2
#include <common/di/Factory.h>
#include <boost/di.hpp>
#include <utility>

/*
 * TODO : check T at compile time : static assert, enable_if, ...
 */
template<class T, class...TArgs>
class BoostFactory : public Factory<T, TArgs...> {
public:
    BoostFactory(boost::di::injector<T>& module_) : module(module_) {
    }

    T create(TArgs... args) override {
        auto injector = boost::di::make_injector(
                module,
                boost::di::bind<TArgs>().to(std::forward<TArgs>(args))[boost::di::override]...
                );

        return module.template create<T>();
    }

private:
    boost::di::injector<T>& module;
};