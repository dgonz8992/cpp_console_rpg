//
// Created by David Gonzalez on 7/31/26.
//

#include <iostream>
#include <utility>
#include <algorithm>
#include <random>
#include "Player.h"


Player::Player(std::string name, int health, int strength, int weight)
    : playerName(std::move(name)), playerHealth(health), playerStrength(strength), playerMaxWeight(weight)
{
}

void Player::getPlayerItem(int backpackSlot) const
{
    if (backpackSlot < 0 || backpackSlot >= backpack.size())
        std::cout << "Invalid slot!\n\n";
    else if (backpack[backpackSlot].getItemName().empty())
        std::cout << "Slot is empty!\n\n";
    else
        std::cout << "Item: " << backpack[backpackSlot].getItemName() << "\n\n";

}

void Player::playerPickupItem(Item& item)
{

    if (playerCurrentWeight + item.getItemWeight() > playerMaxWeight)
    {
        std::cout << "Too heavy!\n\n";
    }
    else
    {
        backpack.push_back(item);
        playerCurrentWeight += item.getItemWeight();
        std::cout << "Picked up " << item.getItemName() << "\n\n";
    }
}

void Player::playerDropItem(int backpackSlot)
{
    if (backpackSlot < 0 || backpackSlot >= backpack.size())
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
        playerCurrentWeight -= backpack[backpackSlot].getItemWeight();
        std::cout << backpack[backpackSlot].getItemName() << " dropped.\n\n";
        backpack[backpackSlot] = empty;
    }
}

void Player::playerTakeDamage(int damageTaken)
{
    playerHealth -= damageTaken;
    playerHealth = std::clamp(playerHealth, 0, maxPlayerHealth);

    std::cout << "You took " << damageTaken << " points of damage\n";

    if (playerHealth == 0)
       {std::cout << getPlayerName() << " died!\n\n";}
    else
        std::cout << "Current health: " << getPlayerHealth() << "\n\n";
}

int Player::playerDealDamage(const Item& item) const
{
    int damageDealt = playerStrength + item.getItemStrength();

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());

    std::uniform_int_distribution<int> distribution(damageDealt - playerStrength, damageDealt);

    int randomNumber = distribution(generator);

    return randomNumber;
}

void Player::getPlayerBackpackContents() const
{
    std::cout << "Backpack contents: \n";
    for (int i = 0; i < backpack.size(); i++)
    {
        std::cout << "Item " << i << ":\n";
        std::cout << "Name: " << backpack[i].getItemName() << std::endl;
        std::cout << "Strength: " << backpack[i].getItemStrength() << std::endl;
        std::cout << "Rarity: " << backpack[i].getItemRarity() << std::endl;
        std::cout << "Weight: " << backpack[i].getItemWeight() << std::endl;
        std::cout << '\n';
    }
    std::cout << "+++++++++++++++++++++++++++++++++++++\n\n";
}
