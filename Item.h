//
// Created by David Gonzalez on 7/31/26.
//

#ifndef FORLEARNING_ITEM_H
#define FORLEARNING_ITEM_H
#include <string>

class Item
{
public:
    enum class Rarity
    {
        none,
        white,
        green,
        blue,
        purple,
        gold
    };

    Item (std::string name, Rarity rarity, int strength, int weight);
    void itemDamage();
    [[nodiscard]] std::string getItemName() const {return itemName;}
    [[nodiscard]] std::string getItemRarity() const;
    [[nodiscard]] int getItemStrength() const {return itemStrength;}
    [[nodiscard]] int getItemWeight() const {return itemWeight;}

private:
    std::string itemName;
    Rarity itemRarity;
    int itemStrength = 10;
    int itemWeight = 10;

};


#endif //FORLEARNING_ITEM_H