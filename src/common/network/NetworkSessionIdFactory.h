#pragma once

#include <common/di/Factory.h>
#include <common/uuid/UUIDFactory.h>
#include "NetworkSessionId.h"

class NetworkSessionIdFactory : public Factory<NetworkSessionId> {
public:
    NetworkSessionIdFactory(UUIDFactory& uuidFactory);

    NetworkSessionId create() override;

private:
    UUIDFactory& uuidFactory;
};
