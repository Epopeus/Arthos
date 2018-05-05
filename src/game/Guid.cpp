#include "Guid.h"
#include <utility>

Guid::Guid(uint64_t intValue_) : intValue(intValue_) {
}

Guid::~Guid() {
}

uint64_t Guid::getIntValue() const {
    return intValue;
}

size_t GuidHasher::operator()(const Guid& guid) const {
    return std::hash<uint64_t >()(guid.getIntValue());
}

bool GuidComparator::operator()(const Guid& guid1, const Guid& guid2) const {
    return guid1.getIntValue() == guid2.getIntValue();
}