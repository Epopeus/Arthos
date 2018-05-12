#pragma once

#include <stdint.h>
#include <stddef.h>

class Guid {
public:
    Guid(uint64_t intValue_);

    ~Guid();

    uint64_t getIntValue() const;
    bool equals(const Guid& otherGuid) const;
private:
    uint64_t intValue;
};

bool operator==(const Guid& g1, const Guid& g2);
bool operator!=(const Guid& g1, const Guid& g2);

struct GuidHasher  {
    size_t operator()(const Guid& guid) const;
};

struct GuidComparator
{
    bool operator()(const Guid& guid1, const Guid& guid2) const;
};