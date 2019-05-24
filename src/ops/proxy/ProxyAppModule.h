#pragma once

#include <common/di/boost/AppModule.h>

auto ProxyAppModule = [](int argc, const char** argv) {
    return boost::di::make_injector(
            AppModule(argc, argv)
    );
};
