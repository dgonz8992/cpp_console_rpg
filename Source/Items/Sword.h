//
// Created by David Gonzalez on 8/8/26.
//

#ifndef CPP_CONSOLE_RPG_SWORD_H
#define CPP_CONSOLE_RPG_SWORD_H
#include "Item.h"

class Sword : public Item
{
public:

    Sword(std::string name, Rarity itemRarity, int weight, int maxDamage);
    [[nodiscard]] int getDamage() const override {return RNG(static_cast<int>(damage * 0.75), damage);};
    [[nodiscard]] int getMaxDistance() const {return maxDistance;}

private:
    int maxDistance = 10;
    int damage;
};


#endif //CPP_CONSOLE_RPG_SWORD_H