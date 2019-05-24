#pragma once

template<typename T>
class CommandGateway {
public:
    virtual void run(T args) = 0;
};
