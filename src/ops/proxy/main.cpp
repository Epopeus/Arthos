#include <common/app/ServiceFactory.h>

int main(int argc, const char** argv) {
    ServiceFactory appFactory = ServiceFactory();
    Service proxyService = appFactory.create<ProxyService>(argc, argv);
    proxyService.run();
}