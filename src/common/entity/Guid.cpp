#include "Guid.h"
#include <functional>

Guid::Guid(uint64 intValue_) : intValue(intValue_) {
}

Guid::~Guid() {
}

uint64 Guid::getIntValue() const {
    return intValue;
}

bool Guid::equals(const Guid& otherGuid) const {
    return intValue == otherGuid.getIntValue();
}

bool operator==(const Guid& g1, const Guid& g2) {
    return g1.equals(g2);
}

size_t GuidHasher::operator()(const Guid& guid) const {
    return std::hash<uint64 >()(guid.getIntValue());
}

bool GuidComparator::operator()(const Guid& guid1, const Guid& guid2) const {
    return guid1 == guid2;
}