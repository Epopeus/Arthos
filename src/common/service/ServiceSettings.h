#pragma once
#include <string>

class ServiceSettings {
public:
    ServiceSettings(int listenPort_, const std::string &connectAddress_, int connectPort_) : listenPort(listenPort_), connectAddress(connectAddress_), connectPort(connectPort_) {}

    int listenPort;
    std::string connectAddress;
    int connectPort;
};

