#include <common/service/ServiceFactory.h>

int main(int argc, const char** argv) {
    ServiceFactory serviceFactory = ServiceFactory();
    Service proxyService = serviceFactory.create<ProxyService>(argc, argv);
    proxyService.run();
}