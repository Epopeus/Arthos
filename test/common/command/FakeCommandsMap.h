#pragma once

#include <common/command/CommandsMap.h>
#include <common/network/Bytes.h>
#include "FakeCommand.h"

class FakeCommandsMap : public CommandsMap<Bytes&> {
public:
    FakeCommandsMap(FakeCommandAdapter& adapter);

    CommandAdapter<Bytes&>& getAdapterForRequest(Bytes& request) override;

private:
    FakeCommandAdapter& adapter;
};
