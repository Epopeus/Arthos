#pragma once

#include <vector>

struct Test {
    int test;
};

class FakeCommand {
public:
    void run(int arg) {
        invokeArgs.push_back(arg);
    }

    std::vector<int> invokeArgs;
};

class FakeCommandAdapter : public CommandAdapter<Bytes&> {
public:
    FakeCommandAdapter() {}

    void run(Bytes& args) override {
        invokeArgs.push_back(args);
    }

    std::vector<Bytes> invokeArgs;

};