#pragma once

#include <common/service/Loadable.h>

class FakeLoadable : public Loadable {
public:
    void load() override;

    bool loaded = false;
};
