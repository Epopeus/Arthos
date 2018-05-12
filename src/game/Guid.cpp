#include "Guid.h"
#include <utility>

Guid::Guid(uint64_t intValue_) : intValue(intValue_) {
}

Guid::~Guid() {
}

uint64_t Guid::getIntValue() const {
    return intValue;
}

bool Guid::equals(const Guid& otherGuid) const {
    return intValue == otherGuid.getIntValue();
}

bool operator==(const Guid& g1, const Guid& g2) {
    return g1.equals(g2);
}

bool operator!=(const Guid& g1, const Guid& g2) {
    return !(g1 == g2);
}

size_t GuidHasher::operator()(const Guid& guid) const {
    return std::hash<uint64_t >()(guid.getIntValue());
}

bool GuidComparator::operator()(const Guid& guid1, const Guid& guid2) const {
    return guid1 == guid2;
}