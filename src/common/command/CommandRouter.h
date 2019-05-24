#pragma once

template<class T>
class CommandRouter {
public:
    virtual void route(T& request) = 0;
};