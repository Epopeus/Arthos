#pragma once

#include <unordered_set>
#include "Store.h"
#include "common/type/ValueObject.h"

template<class K, typename T>
class KeyStore : public Store<K> {
public:
    void add(K key) {
        data.insert(key);
    }

    bool has(K key) {
        return data.count(key);
    }

    int count() {
        return data.size();
    }

private:
    std::unordered_set<K, ValueObject::Hasher<T>> data;
};