#pragma once

#include "Guild.h"

class GuildRepository {
public:
    GuildRepository();

    ~GuildRepository();

    Guild& getGuildById(int guildId);
};

