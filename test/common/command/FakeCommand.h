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

class FakeCommandGateway : public CommandGateway<Bytes&> {
public:
    FakeCommandGateway() {}

    void run(Bytes& args) override {
        invokeArgs.push_back(args);
    }

    std::vector<Bytes> invokeArgs;

};