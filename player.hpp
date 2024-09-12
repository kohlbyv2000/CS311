// player.hpp
// Kohlby Vierthaler
// 2024/09/05
// Header file for Player class

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <ostream>
#include <string>



////**** PLAYER CLASS ****////



class Player {
    
    public:

    //** Constructor Functions **//

    // Default constructor
    Player() {
        getRealName();
        getUsername();
        getGames();
    }

    // 3-parameter constructor, sets info to given data
    Player(const std::string &realName, const std::string &userName, int numGames) {
        setRealName(realName);
        setUsername(userName);
        setGames(numGames);
    }


    //** Getter and Setter functions **//

    std::string getRealName() const {
        return "UNKNOWN";
    }

    std::string getUsername() const {
        return "UNKNOWN";
    }
    
    int getGames() const {
        return 0;
    }

    void setRealName(const std::string &realname) {
        return;
    }
    
    void setUsername(const std::string &username) {
        return;
    }
    
    void setGames(int games) {
        return;
    }


    //** General member functions **//

    bool inactive() {
        const Player &player1 = *this;
        if (player1.numGames == 0) {
            return true;
        } else {
            return false;
        }
    }

    // std::string toString() {
       //TO DO
    // }
    


    //** Operator functions **//

    // Pre-increment
    Player &operator++() {
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
        --numGames;
        return *this;
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


friend bool operator!=(const Player &player1, const Player &player2) {
    if (player1.realName != player2.realName) {
        return true;
    } else {
        return false;
    }
}

friend bool operator==(const Player &player1, const Player &player2) {
    if (player1.realName == player2.realName) {
        if (player1.userName == player2.userName) {
            if (player1.numGames == player2.numGames) {
                return true;
            }
        }
    } else {
        return false;
    }
}

#endif