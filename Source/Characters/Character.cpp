#include <iostream>
#include <utility>
#include <algorithm>
#include "Character.h"

Character::Character(std::string name, int health, int strength, int weight)
    : characterName(std::move(name)), maxCharacterHealth(health), characterHealth(health),
        characterStrength(strength), characterMaxWeight(weight)
{}

bool Character::pickupItem(std::unique_ptr<Item> item)
{

    if (characterCurrentWeight + item->getItemWeight() > characterMaxWeight)
    {
        std::cout << "Too heavy!\n\n";
        return false;
    }
    characterCurrentWeight += item->getItemWeight();
    std::cout << "Picked up " << item->getItemName() << "\n\n";
    inventory.stashItem(std::move(item));
    return true;
}

void Character::dropItem(const size_t backpackSlot)
{
    std::unique_ptr<Item> itemToDrop = inventory.dropItem(backpackSlot);

    if (itemToDrop == nullptr)
    {
        std::cout << "No item in this slot or invalid slot.\n\n";
    }
    else
    {
        characterCurrentWeight -= itemToDrop->getItemWeight();
        std::cout << "Dropped " << itemToDrop->getItemName() << "\n\n";
    }
}

void Character::takeDamage(const Character& attacker)
{
    if (RNG(0, 10) < 4)
    {
        std::cout << attacker.getName() << " missed!\n";
        return;
    }

    int damageTaken = attacker.dealDamage();
    characterHealth -= damageTaken;
    characterHealth = std::clamp(characterHealth, 0, maxCharacterHealth);

    std::cout << attacker.getName() << " inflicted " << damageTaken << " points of damage to " << characterName << std::endl;

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

    int damageOutput = RNG(damageDealt - characterStrength, damageDealt);

    return damageOutput;

}

void Character::equipItem(const size_t backpackSlot)
{
    std::unique_ptr<Item> newItem = inventory.equipItem(backpackSlot);

    if (newItem == nullptr)
    {
        std::cout << "Invalid or Empty slot!\n\n";
        inventory.stashItem(std::move(newItem), backpackSlot);
        return;
    }
    std::swap(characterItemEquipped, newItem);
    inventory.stashItem(std::move(newItem), backpackSlot);
    std::cout << characterItemEquipped->getItemName() << " equipped.\n\n";
}

void Character::getItem(const size_t backpackSlot) const
{
    inventory.getItem(backpackSlot);
}

void Character::useItem(size_t backpackSlot)
{
    std::unique_ptr<Item> item = inventory.equipItem(backpackSlot);

    if (item == nullptr)
    {
        std::cout << "Invalid inventory slot\n\n";
        return;
    }

    const bool useItem = item->itemEffects(*this);

    if (!useItem)
        inventory.stashItem(std::move(item), backpackSlot);
}

void Character::getBackpackContents() const
{
    inventory.getBackpackContents();
}
