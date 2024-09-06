// player.hpp
// Kohlby Vierthaler
// 2024/09/05
// Header file for Player class

#ifndef FILE_PLAYER_HPP_INCLUDED
#define FILE_PLAYER_HPP_INCLUDED

#include <string>



////**** PLAYER CLASS ****////



class Player {
    
    public:

    //** Constructor Functions **//

    // Default constructor
    PlayerInfo() {
        realName = "UNKNOWN";
        userName = "UNKNOWN";
        numGames = 0;
    }

    // 3-parameter constructor, sets info to given data
    PlayerInfo(std::string realName, std::string userName, int numGames) {
        setInfo(realName, userName, numGames);
    }


    //* General member functions *//

    getRealName() {
        return "";
    }

    getUsername() {
        return "";
    }
    
    getGames() {
        return 0;
    }



    private:
    
    //** Private data members **//
    std::string realName;
    std::string userName;
    int numGames;
}

#endif