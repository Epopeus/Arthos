#pragma once


#include <string>
#include <common/entity/Guid.h>

class Character {
public:
    Character(Guid id_, std::string name_);

private:
    Guid id;
    std::string name;
};

