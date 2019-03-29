#pragma once

#include <common/di/Factory.h>
#include <utility>

template<class T, class... TArgs>
class FakeFactory : public Factory<T, TArgs...> {
public:
    T create(TArgs... args) override {
        return *(new T(std::forward<TArgs>(args)...));
    }
};