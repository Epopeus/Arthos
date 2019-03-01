#include <common/service/ServiceFactory.h>
#include "ProxyService.h"

int main(int argc, const char** argv) {
    ServiceFactory serviceFactory = ServiceFactory();
    ProxyService proxyService = serviceFactory.create<ProxyService>(argc, argv);
    proxyService.run();
}