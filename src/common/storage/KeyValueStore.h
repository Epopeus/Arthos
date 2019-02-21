#pragma once

#include "Store.h"
#include "common/type/ValueObject.h"

template<class K, class V, typename T>
class KeyValueStore : public Store<K> {
public:
    void add(K key, V& value) {
        data.insert(std::make_pair(key, value));
    }

    OptionalRef<V> find(K key) {
        OptionalRef<V> result = OptionalRef<V>();
        auto value = data.find(key);

        if (value != data.end())
            result.swap(value->first);

        return result;
    }

private:
    std::unordered_map<K, V&, ValueObject::Hasher<T>> data;
};