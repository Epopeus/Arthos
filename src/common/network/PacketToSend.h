#pragma once

#include "Bytes.h"

class PacketToSend {
public:
    virtual Bytes& toBytes() = 0;

private:
    Bytes& bytes;
};

