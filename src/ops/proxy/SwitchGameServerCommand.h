#pragma once

#include <string>

class SwitchGameServerCommand {
public:
    SwitchGameServerCommand(std::string newAddress, int newPort);
private:
    std::string newAddress;
    int newPort;
};