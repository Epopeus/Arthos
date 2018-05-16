#pragma once
#include <string>

class AuthSettings {
public:
    AuthSettings();
    ~AuthSettings();

    std::string serverIp;
    int serverPort;
};

