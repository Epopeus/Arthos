#pragma once

#include <boost/di/extension/injections/factory.hpp>


template<class T, class...TArgs>
class Factory {
public:
    virtual T create(TArgs...) = 0;
};