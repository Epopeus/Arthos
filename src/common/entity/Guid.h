#pragma once

#include <stddef.h>
#include "common/type/numbers.h"

class Guid {
public:
    Guid(uint64 intValue_);

    ~Guid();

    uint64 getIntValue() const;
    bool equals(const Guid& otherGuid) const;
private:
    uint64 intValue;
};

bool operator==(const Guid& g1, const Guid& g2);

struct GuidHasher  {
    size_t operator()(const Guid& guid) const;
};

struct GuidComparator
{
    bool operator()(const Guid& guid1, const Guid& guid2) const;
};