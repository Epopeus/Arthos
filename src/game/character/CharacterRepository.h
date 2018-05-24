#pragma once


#include "Character.h"

class CharacterRepository {
public:
    CharacterRepository();

    void add(Character character);

    void find(std::string& name);
};

