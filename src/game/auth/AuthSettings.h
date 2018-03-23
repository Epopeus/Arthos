#pragma once
#include "../../Settings.h"
#include <iostream>

class AuthSettings : public Settings {
public:
    AuthSettings();
    ~AuthSettings();

    std::string m_serverIp;
    int m_serverPort;
};

