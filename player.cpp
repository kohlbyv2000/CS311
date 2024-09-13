// player.cpp
// Kohlby Vierthaler
// 2024/09/05
// Code for High Quality Class

#include "player.hpp"
#include <ostream>
#include <cassert>

void initPlayer() {
    Player player1;
    return;
}

std::ostream &operator<<(std::ostream &str, const Player &obj) {
    std::string realName;
    std::string userName;
    int numGames;

    obj.getRealName(realName) const;
    obj.getUsername(userName) const;
    obj.getGames(numGames) const;

    str << realName << " (" << userName << "): " << numGames;
    return str;
}