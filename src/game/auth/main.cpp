#include <common/service/ServiceFactory.h>
#include "AuthService.h"

int main(int argc, const char** argv) {
    ServiceFactory serviceFactory = ServiceFactory();
    AuthService service = serviceFactory.create<AuthService>(argc, argv);
    service.run();
}