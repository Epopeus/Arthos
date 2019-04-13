#pragma once

class Launchable {
public:
    virtual void launch() = 0;
    virtual void shutdown() = 0;
};