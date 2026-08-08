#ifndef FORLEARNING_PLAYER_H
#define FORLEARNING_PLAYER_H

#include <vector>
#include <string>
#include "Item.h"

class Character
{
public:
    Character(std::string name, int health, int strength, int weight);

    void pickupItem(std::unique_ptr<Item> item);
    void dropItem(size_t backpackSlot);
    void takeDamage(Character& character);
    [[nodiscard]] int dealDamage() const;
    void equipItem(size_t backpackSlot);
    void useItem(int backpackSlot);

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
    std::string characterName;
    int maxCharacterHealth;
    int characterHealth = maxCharacterHealth;

    int characterStrength = 10;

    int characterMaxWeight = 50;
    int characterCurrentWeight = 0;

    std::vector<std::unique_ptr<Item>> backpack;
    std::unique_ptr<Item> characterItemEquipped = nullptr;
};

#endif //FORLEARNING_PLAYER_H