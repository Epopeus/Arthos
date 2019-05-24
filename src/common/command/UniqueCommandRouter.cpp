#include "UniqueCommandRouter.h"

UniqueCommandRouter::UniqueCommandRouter(BytesCommandGateway& gateway) : gateway(gateway) {

}

void UniqueCommandRouter::route(Bytes& request) {
    gateway.run(request);
}

