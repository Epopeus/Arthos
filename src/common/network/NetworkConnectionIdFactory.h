#pragma once

#include <common/uuid/UUID.h>
#include "NetworkConnectionId.h"

class NetworkConnectionIdFactory : public Factory<NetworkConnectionId> {
public:
    NetworkConnectionIdFactory(UUIDFactory& uuidFactory);
    NetworkConnectionId create() override;

private:
    UUIDFactory& uuidFactory;
};
