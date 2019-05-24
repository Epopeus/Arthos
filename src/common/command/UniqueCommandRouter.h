#pragma once

#include "CommandRouter.h"
#include "BytesCommandGateway.h"

class UniqueCommandRouter : public CommandRouter<Bytes&> {
public:
    UniqueCommandRouter(CommandGateway<Bytes&>& gateway);

    void route(Bytes& request) override;
private:
    BytesCommandGateway& gateway;
};
