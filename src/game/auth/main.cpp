#include <common/app/ServiceFactory.h>
#include "AuthService.h"

int main(int argc, const char** argv) {
    ServiceFactory appFactory = ServiceFactory();
    AuthService app = appFactory.create<AuthService>(argc, argv);
    app.run();
}