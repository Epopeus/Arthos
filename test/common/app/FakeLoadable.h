#pragma once

#include <common/app/Loadable.h>

class FakeLoadable : public Loadable {
public:
    void load() override;

    bool loaded = false;
};
