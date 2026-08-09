//
// Created by David Gonzalez on 8/8/26.
//

#include "Sword.h"

Sword::Sword(std::string name, Rarity itemRarity, int weight, int maxDamage)
    : Item(std::move(name), ItemType::sword, itemRarity, weight), damage(maxDamage)
{}

