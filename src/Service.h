#pragma once


class Service {
public:
    virtual ~Service() {};

    virtual void run() = 0;
};

