#pragma once

#include <vector>
#include "common/type/numbers.h"
#include <any>

class BinaryData {
public:
    BinaryData();
    BinaryData(std::vector<uint8> data_);
    ~BinaryData();

    BinaryData& operator<<(std::any value);
    BinaryData& operator>>(std::any& value);
private:
    std::vector<uint8> data;
};