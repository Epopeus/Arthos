#pragma once


#include "GameClientCommand.h"

class TestCommand : public GameClientCommand<int, std::string, int> {
public:
    TestCommand(Guid& callingCharId);

    void run(int test, std::string test2, int test3) override;
};

