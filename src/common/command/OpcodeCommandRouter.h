#pragma once

#include "CommandRouter.h"
#include <vector>
#include <functional>
#include "BytesCommandGateway.h"

using BytesCommandsMap = std::vector<std::reference_wrapper<BytesCommandGateway>>;

class OpcodeCommandRouter : public CommandRouter<Bytes&> {
public:
    OpcodeCommandRouter(BytesCommandsMap& commandsMap);
    void route(Bytes& request) override;
private:
    BytesCommandsMap& commandsMap;
};

