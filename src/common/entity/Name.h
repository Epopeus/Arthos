#pragma once

#include <common/type/ValueObject.h>
#include <string>

class Name : public ValueObject<std::string> {
public:
    Name(std::string stringValue_);
};