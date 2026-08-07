#ifndef FORLEARNING_PLAYER_H
#define FORLEARNING_PLAYER_H

#include <vector>
#include <string>
#include "Item.h"

class Character
{
public:
    Character(std::string name, int health, int strength, int weight);

    void pickupItem(const Item& item);
    void dropItem(size_t backpackSlot);
    void takeDamage(int damageTaken);
    [[nodiscard]] int dealDamage() const;
    void equipItem(size_t backpackSlot);
    void useItem(Item& item);

    //Setters
    void setHealth(int newPlayerHealth) {characterHealth = newPlayerHealth;}
    void setMaxHealth(int newMaxHealth) {maxCharacterHealth = newMaxHealth;}
    void setStrength(int newCharacterStrength) {characterStrength = newCharacterStrength;}
    void setCurrentWeight(int newCharacterCurrentWeight) {characterCurrentWeight = newCharacterCurrentWeight;}
    void setMaxWeight(int newCharacterMaxWeight) {characterMaxWeight = newCharacterMaxWeight;}

    //Getters
    [[nodiscard]] std::string getName() const {return characterName;}
    [[nodiscard]] int getHealth() const {return characterHealth;}
    [[nodiscard]] int getMaxHealth() const {return maxCharacterHealth;}
    [[nodiscard]] int getStrength() const {return characterStrength;}
    [[nodiscard]] int getCurrentWeight() const {return characterCurrentWeight;}
    [[nodiscard]] int getMaxWeight() const {return characterMaxWeight;}
    void getItem(size_t backpackSlot) const;

protected:
    Item hands{"Bare Hands", Item::ItemType::none, Item::Rarity::white, 0};
    Item empty{"Empty", Item::ItemType::none, Item::Rarity::none,  0};

    std::string characterName;
    int maxCharacterHealth;
    int characterHealth = maxCharacterHealth;

    int characterMaxWeight = 50;
    int characterCurrentWeight = 0;

    int characterStrength = 10;

    std::vector<Item> backpack = {hands};
    Item characterItemEquipped = hands;
};

#endif //FORLEARNING_PLAYER_H