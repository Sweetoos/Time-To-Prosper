#pragma once
#include <string>

#include "leaderPerk.h"

class CivLeader
{
private:
    int leaderId;
    std::string leaderName;
    //special unit

    LeaderPerk leaderPerk;
};