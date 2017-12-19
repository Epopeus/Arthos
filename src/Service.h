#pragma once


class Service {
public:
    Service();

    ~Service();

    virtual void run() = 0;
};

