#pragma once
#include "service/Settings.h"
#include <string>

class AuthSettings : public Settings {
public:
    AuthSettings();
    ~AuthSettings();

    std::string serverIp;
    int serverPort;
};

