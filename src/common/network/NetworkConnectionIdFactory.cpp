#include "NetworkConnectionIdFactory.h"

NetworkConnectionIdFactory::NetworkConnectionIdFactory(UUIDFactory& uuidFactory_):uuidFactory(uuidFactory_) {
}

NetworkConnectionId NetworkConnectionIdFactory::create() {
    return NetworkConnectionId(uuidFactory.create());
}