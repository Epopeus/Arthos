#pragma once
#include <iostream>
#include <functional>
#include <vector>
#include "common/type/numbers.h"

class TcpServer {
public:
    virtual void startAcceptingConnections(std::string ip, int port, std::function<void(std::vector<uint8>)> callback) = 0;
    virtual void stopAcceptingConnections() = 0;
    virtual ~TcpServer() {};
};