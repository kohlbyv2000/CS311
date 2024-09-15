// player.cpp
// Kohlby Vierthaler
// 2024/09/05
// Implementation Code for High Quality Class

#include "player.hpp"
#include <ostream>


//** Definitions of associated global operators **/


// Equal
bool Player::operator==(const Player &player1) const {
    return realName == player1.getRealName() && userName == player1.getUsername() && numGames == player1.getGames();
}

// Not-equal
bool Player::operator!=(const Player &player1) const {
    return !(*this == player1);
}

// Stream insertion
std::ostream &operator<<(std::ostream &str, const Player &obj) {
    str << obj.toString();
    return str;
}