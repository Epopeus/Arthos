#pragma once

#include <common/command/CommandsMap.h>
#include <common/network/Bytes.h>
#include "FakeCommand.h"

class FakeCommandsMap : public CommandsMap<Bytes&> {
public:
    FakeCommandsMap(FakeCommandGateway& gateway);

    CommandGateway<Bytes&>& getGatewayForRequest(Bytes& request) override;

private:
    FakeCommandGateway& gateway;
};
