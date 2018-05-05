#pragma once

#include <stdint.h>
#include <stddef.h>

class Guid {
public:
    Guid(uint64_t intValue_);

    ~Guid();

    uint64_t getIntValue() const;
private:
    uint64_t intValue;
};

struct GuidHasher  {
    size_t operator()(const Guid& guid) const;
};

struct GuidComparator
{
    bool operator()(const Guid& guid1, const Guid& guid2) const;
};