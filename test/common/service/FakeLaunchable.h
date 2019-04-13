#pragma once

#include <common/app/Launchable.h>

class FakeLaunchable : public Launchable {
public:
    void launch() override;
    void shutdown() override;

    bool launched = false;
};
