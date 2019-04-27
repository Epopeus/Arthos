#include "Bytes.h"

Bytes::Bytes(std::initializer_list<AllowedType> values):buffer(values) {
}

Bytes& Bytes::operator<<(AllowedType value) {
    buffer.push_back(value);
    return *this;
}

void Bytes::prepend(AllowedType value) {
    buffer.insert(buffer.begin(), value);
}

bool Bytes::operator==(const Bytes& o) const {
    return buffer == o.buffer;
}
