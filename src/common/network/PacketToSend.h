#pragma once

#include "Bytes.h"

class PacketToSend {
public:
    PacketToSend(Bytes& bytes);

    virtual Bytes& toBytes() = 0;

protected:
    Bytes& bytes;
};

