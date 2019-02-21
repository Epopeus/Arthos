#pragma once

#include <cstddef>
#include <functional>
#include "common/type/Numbers.h"

template<typename V>
class ValueObject {
public:
    ValueObject(V value_):value(value_) {}

    V getValue() const {
        return value;
    }

    bool operator==(const ValueObject<V>& other) const {
        return getValue() == other.getValue();
    }

    bool operator!=(const ValueObject<V>& other) const {
        return !((*this) == other);
    }

    template<typename T>
    struct Hasher {
        size_t operator()(const ValueObject& vo) const {
            return std::hash<T>{}(vo.getValue());
        }
    };

private:
    V value;
};