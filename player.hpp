// player.hpp
// Kohlby Vierthaler
// 2024/09/05
// Header file for Player class

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <ostream>
#include <string>
#include <cassert>



////**** PLAYER CLASS ****////



class Player {
    
    public:

    //** Constructor Functions **//

    // Default constructor
    Player() {
        setRealName("UNKNOWN");
        setUsername("UNKNOWN");
        setGames(0);
    }

    // 3-parameter constructor, sets info to given data
    Player(const std::string &realName, const std::string &userName, int numGames) {
        setRealName(realName);
        setUsername(userName);
        setGames(numGames);
    }


    //** Getter and Setter functions **//

    std::string getRealName() const {
        return realName;
    }

    std::string getUsername() const {
        return userName;
    }
    
    int getGames() const {
        return numGames;
    }

    void setRealName(const std::string &realname) {
        realName = realname;
    }
    
    void setUsername(const std::string &username) {
        userName = username;
    }
    
    void setGames(int games) {
        numGames = games;
    }


    //** General member functions **//
    
    // Is the player inactive?
    bool inactive() {
        const Player &player1 = *this;
        if (player1.numGames == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    // Output the player's info as a string
    std::string toString() const {
        return realName + " (" + userName + "): " + std::to_string(numGames);
    }
    


    //** Operator functions **//

    // Pre-increment
    Player &operator++() {
        assert(numGames > -1);
        ++numGames;
        return *this;
    }

    // Post-increment
    Player operator++([[maybe_unused]] int dummy) {
        auto save = *this;
        ++(*this);
        return save;
    }

    // Pre-decrement
    Player operator--() {
        assert(numGames >= 0);
        --numGames;
        if (numGames > 0) {
            return *this;
        }
    }

    // Post-decrement
    Player operator--([[maybe_unused]] int dummy) {
        auto save = *this;
        --(*this);
        return save;
    }

    private:
    
    //** Private data members **//
    std::string realName;
    std::string userName;
    int numGames;

}; // End of Player class


//** Global operators associated with the Player class **//

bool operator!=(const Player &player1, const Player &player2) {
    if (player1.getRealName() != player2.getRealName()) {
        return true;
    } else {
        return false;
    }
}

bool operator==(const Player &player1, const Player &player2) {
    if (player1.getRealName() == player2.getRealName()) {
        if (player1.getUsername() == player2.getUsername()) {
            if (player1.getGames() == player2.getGames()) {
                return true;
            }
        }
    } else {
        return false;
    }
}

std::ostream &operator<<(std::ostream &str, const Player &obj);

#endif