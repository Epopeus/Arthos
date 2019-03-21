#include "FakeCommandOutputBuffer.h"

CommandOutputBuffer& FakeCommandOutputBuffer::operator<<(AllowedType value) {
    buffer.push_back(value);
    return *this;
}
