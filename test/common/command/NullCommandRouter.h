#pragma once

#include <common/network/Bytes.h>
#include <common/command/CommandRouter.h>

class NullCommandRouter : public CommandRouter<Bytes&> {
public:
    void route(Bytes& request) override;
};
