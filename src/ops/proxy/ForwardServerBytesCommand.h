#pragma once

#include <common/command/Command.h>
#include <common/network/Bytes.h>
#include <common/network/NetworkConnectionRepository.h>

class ForwardServerBytesCommand : public Command<Bytes&> {
public:
    ForwardServerBytesCommand(NetworkConnectionRepository& connectionsRepo);

    void run(Bytes& args) override;

private:
    NetworkConnectionRepository& connectionsRepo;
};
