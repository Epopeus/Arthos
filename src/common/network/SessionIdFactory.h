#pragma once

#include <common/di/Factory.h>
#include <common/uuid/UUIDFactory.h>
#include "SessionId.h"

class SessionIdFactory : public Factory<SessionId> {
public:
    SessionIdFactory(UUIDFactory& uuidFactory);

    SessionId create() override;

private:
    UUIDFactory& uuidFactory;
};
