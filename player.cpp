// player.cpp
// Kohlby Vierthaler
// 2024/09/05
// Implementation Code for High Quality Class

#include "player.hpp"
#include <ostream>


//** Definitions of associated global operators **/


// Not-equal operator
bool Player::operator!=(const Player &player1) const {
    return !(*this == player1);
}

// Equal operator
bool Player::operator==(const Player &player1) const {
    return realName == player1.getRealName() && 
    userName == player1.getUsername() &&
    numGames == player1.getGames();
}

// Stream insertion operator
std::ostream &operator<<(std::ostream &str, const Player &obj) {

    auto realName = obj.getRealName();
    auto userName = obj.getUsername();
    //auto numGames = obj.getGames();
    
    str << obj.toString();
    return str;
}