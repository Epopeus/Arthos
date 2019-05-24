#include <common/di/boost/BoostFactory.h>
#include "ProxyAppModule.h"
#include "ProxyApp.h"

int main(int argc, const char** argv) {
    boost::di::injector<ProxyApp> injector = ProxyAppModule(argc, argv);
    ProxyApp app = injector.create<ProxyApp>();
    app.run();
}