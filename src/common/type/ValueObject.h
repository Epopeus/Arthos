#pragma once

#include <cstddef>
#include <functional>
#include "common/type/Numbers.h"

template<typename T>
class ValueObject {
public:
    ValueObject(T value_):value(value_) {}

    T getValue() const {
        return value;
    }

    bool operator==(const ValueObject<T>& other) const {
        return value == other.getValue();
    }

    bool operator!=(const ValueObject<T>& other) const {
        return !((*this) == other);
    }

private:
    T value;
};

template<typename T, typename P>
struct Hasher {
    size_t operator()(const T& vo) const {
        return std::hash<P>{}(vo.getValue());
    }
};