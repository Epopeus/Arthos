#pragma once

#include "TcpClient.h"

class BoostTcpClient : public TcpClient {
public:
    BoostTcpClient();
    void connect(std::string ip, int port, std::function<void(std::vector<uint8>)> callback) override;
};

