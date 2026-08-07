#ifndef CPP_CONSOLE_RPG_PLAYER_H
#define CPP_CONSOLE_RPG_PLAYER_H
#include "Character.h"


class Player : public Character
{
public:
    Player(std::string name, int health, int strength, int weight);

    void getPlayerBackpackContents() const;

private:
};


#endif //CPP_CONSOLE_RPG_PLAYER_H