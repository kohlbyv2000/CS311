// player.cpp
// Kohlby Vierthaler
// 2024/09/05
// Code for High Quality Class

#include "player.hpp"
#include <ostream>
#include <cassert>


// Stream insertion operator
std::ostream &operator<<(std::ostream &str, const Player &obj) {

    auto realName = obj.getRealName();
    auto userName = obj.getUsername();
    auto numGames = obj.getGames();
    
    str << obj.toString();
    //str << realName << " (" << userName << "): " << numGames;
    return str;
}