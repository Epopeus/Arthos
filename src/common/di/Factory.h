#pragma once

template<class T, class... TArgs>
class Factory {
public:
    virtual T create(TArgs&&... args) = 0;
};