#include <common/app/ServiceFactory.h>
#include "AuthService.h"

int main(int argc, const char** argv) {
    AppFactory appFactory = AppFactory();
    AuthService app = appFactory.create<AuthService>(argc, argv);
    app.run();
}