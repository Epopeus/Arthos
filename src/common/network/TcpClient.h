#pragma once
#include <functional>
#include <vector>
#include "common/type/Numbers.h"

class TcpClient {
public:
    virtual void connect(std::string ip, int port, std::function<void(std::vector<uint8>)> callback) = 0;
    virtual ~TcpClient() {};
};