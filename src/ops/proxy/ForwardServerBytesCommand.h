#pragma once

#include <common/network/Bytes.h>
#include <common/network/NetworkConnectionRepository.h>

class ForwardServerBytesCommand {
public:
    ForwardServerBytesCommand(NetworkConnectionRepository& connectionsRepo);

    void run(Bytes& args);

private:
    NetworkConnectionRepository& connectionsRepo;
};
