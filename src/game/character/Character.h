#pragma once


#include <string>
#include <common/entity/Guid.h>

struct Character {
public:
    Character(Guid id_, std::string name_);

    Guid id;
    std::string name;
};