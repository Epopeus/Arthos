#pragma once

#include <common/command/CommandOutputBuffer.h>
#include <vector>
#include <variant>

class FakeCommandOutputBuffer : public CommandOutputBuffer {
public:
    std::vector<AllowedType> buffer;

private:
    CommandOutputBuffer& operator<<(AllowedType value) override;
};
