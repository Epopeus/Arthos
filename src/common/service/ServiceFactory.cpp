#define BOOST_DI_CFG_DIAGNOSTICS_LEVEL 2

#include <common/di/ServiceModule.h>
#include "ServiceFactory.h"

Service ServiceFactory::create(int argc, const char** argv) {
    const auto injector = boost::di::make_injector(
            ServiceModule()
    );

    return injector.create<Service>();
}
