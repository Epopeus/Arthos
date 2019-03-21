#pragma once

#include <common/service/Launchable.h>

class FakeLaunchable : public Launchable {
public:
    void launch() override;
    void shutdown() override;

    bool launched = false;
};
