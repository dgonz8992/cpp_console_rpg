#ifndef FORLEARNING_ITEM_H
#define FORLEARNING_ITEM_H

#include <string>
#include <iostream>

class Character;
int RNG(int min, int max);

class Item
{
public:
    enum class Rarity
    {
        none = 0,
        white = 10,
        green = 20,
        blue = 30,
        purple = 40,
        gold = 50
    };

    enum class ItemType
    {
        none,
        sword,
        shield,
        helmet,
        chest,
        leggings,
        potion,

    };

    Item(std::string name, ItemType item, Rarity rarity, int weight);
    virtual ~Item() = default;

    virtual bool itemEffects(Character& character)
    {
        std::cout << "Item cannot be used.\n\n";
        return false;
    }

    [[nodiscard]] virtual int getDamage() const
    {
        std::cout << "This is not a weapon\n\n";
        return 0;
    }


    [[nodiscard]] std::string getItemName() const {return itemName;}
    [[nodiscard]] std::string getItemRarityColor() const;
    [[nodiscard]] int getItemRarityStrength() const {return static_cast<int>(itemRarity);}
    [[nodiscard]] std::string getItemType() const;
    [[nodiscard]] int getItemWeight() const {return itemWeight;}

protected:
    std::string itemName;
    Rarity itemRarity;
    ItemType itemType;
    int itemWeight;

};

#endif //FORLEARNING_ITEM_H