#include "Item.h"
#include <utility>

Item::Item(std::string name, ItemType item, Rarity rarity, int weight) :
            itemName(std::move(name)), itemType(item), itemRarity(rarity), itemWeight(weight)
{
}

std::string Item::getItemRarityColor() const
{
    switch (itemRarity)
    {
        case Rarity::none: return "None";
        case Rarity::white: return "White";
        case Rarity::green: return "Green";
        case Rarity::blue: return "Blue";
        case Rarity::purple: return "Purple";
        case Rarity::gold: return "Gold";
        default: return "Rarity Unknown";
    }
}

std::string Item::getItemType() const
{
    switch (itemType)
    {
        case ItemType::none: return "No Type";
        case ItemType::sword: return "Sword";
        case ItemType::shield: return "Shield";
        case ItemType::helmet: return "Helmet";
        case ItemType::chest: return "Chest";
        case ItemType::leggings: return "Leggings";
        case ItemType::potion: return "Potion";
        default: return "Type Unknown";
    }
}

void Item::getStats() const
{
    std::cout << "Name: " << getItemName() << std::endl,
    std::cout << "Type: " << getItemType() << std::endl;
    std::cout << "Rarity: " << getItemRarityColor() << std::endl;
    std::cout << "Strength: " << getItemRarityStrength() << std::endl;
    std::cout << "Weight: " << getItemWeight() << "\n\n";
}



