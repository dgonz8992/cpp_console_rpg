#include <iostream>
#include <utility>
#include <algorithm>
#include <random>
#include "Character.h"

Character::Character(std::string name, int health, int strength, int weight)
    : characterName(std::move(name)), maxCharacterHealth(health), characterStrength(strength), characterMaxWeight(weight)
{
}

void Character::pickupItem(const Item& item)
{

    if (characterCurrentWeight + item.getItemWeight() > characterMaxWeight)
    {
        std::cout << "Too heavy!\n\n";
        return;
    }

    for (auto& i : backpack)
    {
        if (i.getItemName() == "Empty")
        {
            i = item;
            characterCurrentWeight += item.getItemWeight();
            std::cout << "Picked up " << item.getItemName() << "\n\n";
            return;
        }
    }

    backpack.push_back(item);
    characterCurrentWeight += item.getItemWeight();
    std::cout << "Picked up " << item.getItemName() << "\n\n";
}

void Character::dropItem(const size_t backpackSlot)
{
    if (backpackSlot >= backpack.size())
    {
        std::cout << "Invalid slot!\n\n";
        return;
    }

    if (backpack[backpackSlot].getItemName() == "Bare Hands")
        std::cout << "You cannot drop your own hands!\n\n";

    else if (backpack[backpackSlot].getItemName().empty() || backpack[backpackSlot].getItemName() == "Empty")
        std::cout << "No Item in this slot\n\n";

    else
    {
        characterCurrentWeight -= backpack[backpackSlot].getItemWeight();
        std::cout << backpack[backpackSlot].getItemName() << " dropped.\n\n";
        backpack[backpackSlot] = empty;
    }
}

void Character::takeDamage(const int damageTaken)
{
    characterHealth -= damageTaken;
    characterHealth = std::clamp(characterHealth, 0, maxCharacterHealth);

    std::cout << "You took " << damageTaken << " points of damage\n";

    if (characterHealth == 0)
    {std::cout << getName() << " died!\n\n";}
    else
        std::cout << "Current health: " << getHealth() << "\n\n";
}

int Character::dealDamage() const
{
    int damageDealt = characterStrength + characterItemEquipped.getItemRarityStrength();

    static std::random_device randomDevice;
    static std::mt19937 generator(randomDevice());

    std::uniform_int_distribution<int> distribution(damageDealt - characterStrength, damageDealt);

    int damageOutput = distribution(generator);

    return damageOutput;
}

void Character::equipItem(const size_t backpackSlot)
{
    if (backpackSlot >= backpack.size())
        std::cout << "Invalid backpack slot.\n\n";
    else if (backpack[backpackSlot].getItemName() == "Empty")
    {
        characterItemEquipped = hands;
        std::cout << characterItemEquipped.getItemName() << " equipped.\n\n";
    }
    else
    {
        characterItemEquipped = backpack[backpackSlot];
        std::cout << characterItemEquipped.getItemName() << " equipped.\n\n";
    }
}

void Character::getItem(const size_t backpackSlot) const
{
    if (backpackSlot >= backpack.size())
        std::cout << "Invalid slot!\n\n";
    else if (backpack[backpackSlot].getItemName().empty())
        std::cout << "Slot is empty!\n\n";
    else
        std::cout << "Item: " << backpack[backpackSlot].getItemName() << "\n\n";

}

void Character::useItem(Item& item)
{
    item.itemEffects(*this);
}