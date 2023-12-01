#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {       // The class - Player
private:             // Access specifier - private
    std::string m_name; // Attribute (string variable - player name)
    int m_number;  // Attribute (int variable - player number)

public:
    // Constructor
    Player(std::string, int); // prototype, needs only return type, name and type of parameters

    // Setter
    void SetPlayer(std::string, int);

    // Getter
    std::string getName();
    int getNumber();
};

#endif
