#pragma once

#include <common/network/ClientConnection.h>
#include <vector>
#include <common/type/Numbers.h>

class FakeClientConnection : public ClientConnection {
public:
    void receiveCommand(std::vector<uint8> command) {

    }
};