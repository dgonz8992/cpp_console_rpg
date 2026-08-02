//
// Created by David Gonzalez on 7/31/26.
//

#include "Item.h"
#include <utility>

Item::Item (std::string name, Rarity rarity, int strength, int weight) :
            itemName(std::move(name)), itemRarity(rarity), itemStrength(strength),
            itemWeight(weight)
{
}

std::string Item::getItemRarity() const
{
    switch (itemRarity)
    {
        case Rarity::none: return "None";
        case Rarity::white: return "White";
        case Rarity::green: return "Green";
        case Rarity::blue: return "Blue";
        case Rarity::purple: return "Purple";
        case Rarity::gold: return "Gold";
        default: return "Unknown";
    }

}




