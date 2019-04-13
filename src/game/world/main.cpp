#include <common/di/boost/BoostFactory.h>

int main(int argc, const char** argv) {
    ServiceFactory appFactory = BoostFactory<WorldService>();
    App app = appFactory.create<WorldService>(argc, argv);
    proxyService.run();
}