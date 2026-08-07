#include "Player.h"
#include <iostream>
#include <utility>

Player::Player(std::string name, int health, int strength, int weight)
    : Character(std::move(name), health, strength, weight)
{
}

void Player::getPlayerBackpackContents() const
{
    std::cout << "Backpack contents: \n";
    for (size_t i = 0; i < backpack.size(); i++)
    {
        std::cout << "Item " << i << ":\n";
        std::cout << "Name: " << backpack[i].getItemName() << std::endl;
        std::cout << "Strength: " << backpack[i].getItemRarityStrength() << std::endl;
        std::cout << "Rarity: " << backpack[i].getItemRarityColor() << std::endl;
        std::cout << "Weight: " << backpack[i].getItemWeight() << std::endl;
        std::cout << '\n';
    }
    std::cout << "+++++++++++++++++++++++++++++++++++++\n\n";
}