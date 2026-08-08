#include <iostream>
#include <utility>
#include <algorithm>
#include <random>
#include "Character.h"

Character::Character(std::string name, int health, int strength, int weight)
    : characterName(std::move(name)), maxCharacterHealth(health), characterStrength(strength), characterMaxWeight(weight)
{}

void Character::pickupItem(std::unique_ptr<Item> item)
{

    if (characterCurrentWeight + item->getItemWeight() > characterMaxWeight)
    {
        std::cout << "Too heavy!\n\n";
        return;
    }

    characterCurrentWeight += item->getItemWeight();
    std::cout << "Picked up " << item->getItemName() << "\n\n";

    bool slotFilled = false;

    for (int i = 0; i < backpack.size(); i++)
    {

        if (backpack[i] == nullptr)
        {
            backpack[i] = std::move(item);
            slotFilled = true;
            break;
        }
    }

    if (!slotFilled)
        backpack.push_back(std::move(item));
}

void Character::dropItem(const size_t backpackSlot)
{
    if (backpackSlot >= backpack.size())
    {
        std::cout << "Invalid slot!\n\n";
    }
    else if (backpack[backpackSlot] == nullptr)
        std::cout << "No Item in this slot\n\n";
    else
    {
        characterCurrentWeight -= backpack[backpackSlot]->getItemWeight();
        std::cout << backpack[backpackSlot]->getItemName() << " dropped.\n\n";
        backpack[backpackSlot] = nullptr;
    }
}

void Character::takeDamage(Character& character)
{
    int damageTaken = character.dealDamage();
    characterHealth -= damageTaken;
    characterHealth = std::clamp(characterHealth, 0, maxCharacterHealth);

    std::cout << character.getName() << " inflicted " << damageTaken << " points of damage to " << characterName << std::endl;

    if (characterHealth == 0)
    {std::cout << getName() << " died!\n\n";}
    else
        std::cout << characterName <<" current health: " << getHealth() << "\n\n";
}

int Character::dealDamage() const
{
    int itemDamage = 0;

   if (characterItemEquipped != nullptr)
       itemDamage = characterItemEquipped->getItemRarityStrength();

    int damageDealt = characterStrength + itemDamage;

    static std::random_device randomDevice;
    static std::mt19937 generator(randomDevice());

    std::uniform_int_distribution<int> distribution(damageDealt - characterStrength, damageDealt);

    int damageOutput = distribution(generator);

    return damageOutput;

}

void Character::equipItem(const size_t backpackSlot)
{
    if (backpackSlot >= backpack.size())
    {
        std::cout << "Invalid backpack slot.\n\n";
        return;
    }
    std::swap(characterItemEquipped, backpack[backpackSlot]);
    std::cout << characterItemEquipped->getItemName() << " equipped\n\n";
}

void Character::getItem(const size_t backpackSlot) const
{
    if (backpackSlot >= backpack.size())
        std::cout << "Invalid slot!\n\n";
    else if (backpack[backpackSlot] == nullptr)
        std::cout << "Slot is empty!\n\n";
    else
    {
        std::cout << "Slot " << backpack[backpackSlot] << ":\n";
        std::cout << "Name: " << backpack[backpackSlot]->getItemName() << std::endl;
        std::cout << "Strength: " << backpack[backpackSlot]->getItemRarityStrength() << std::endl;
        std::cout << "Rarity: " << backpack[backpackSlot]->getItemRarityColor() << std::endl;
        std::cout << "Weight: " << backpack[backpackSlot]->getItemWeight() << std::endl;
        std::cout << '\n';
    }

}

void Character::useItem(int backpackSlot)
{
    backpack[backpackSlot]->itemEffects(*this);
}