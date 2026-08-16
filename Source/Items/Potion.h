//
// Created by David Gonzalez on 8/5/26.
//

#ifndef CPP_CONSOLE_RPG_POTION_H
#define CPP_CONSOLE_RPG_POTION_H

#include "Item.h"

class Potion : public Item
{
public:
    Potion(std::string name, Rarity rarity, int weight, int effectAmount);

   bool itemEffects(Character& character) override;

private:
    int potionEffectAmount;
};


#endif //CPP_CONSOLE_RPG_POTION_H