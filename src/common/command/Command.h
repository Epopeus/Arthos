#pragma once

template<typename... TArgs>
class Command {
public:
    virtual void run(TArgs... args) = 0;
};