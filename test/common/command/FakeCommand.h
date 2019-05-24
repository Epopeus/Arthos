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

class FakeCommandGateway : public BytesCommandGateway {
public:
    FakeCommandGateway(FakeCommand& command):command(command) {}

    void run(Bytes& args) override {
        int arg;
        args >> arg;
        command.run(arg);
    }

    FakeCommand& command;
};