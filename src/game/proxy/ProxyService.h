#pragma once


#include <common/service/Service.h>

class ProxyService : public Service {
public:
    ProxyService();

    void run() override;
};

