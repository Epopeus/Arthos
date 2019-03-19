#include "SessionIdFactory.h"

SessionIdFactory::SessionIdFactory(UUIDFactory& uuidFactory) : uuidFactory(uuidFactory) {

}

SessionId SessionIdFactory::create() {
    return uuidFactory.create();
}
