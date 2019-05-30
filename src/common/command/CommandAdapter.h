#pragma once

template<typename T>
class CommandAdapter {
public:
    virtual void run(T args) = 0;
};
