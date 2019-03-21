#include "NetworkSessionIdFactory.h"

NetworkSessionIdFactory::NetworkSessionIdFactory(UUIDFactory& uuidFactory) : uuidFactory(uuidFactory) {

}

NetworkSessionId NetworkSessionIdFactory::create() {
    return uuidFactory.create();
}
