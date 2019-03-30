#pragma once

#include <common/uuid/UUID.h>

class FakeUUIDFactory : public UUIDFactory {
public:
    UUID create() override;

private:
    int count = 0;
};
