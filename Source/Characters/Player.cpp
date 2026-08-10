#include "Player.h"
#include <iostream>
#include <utility>

Player::Player(std::string name, int health, int strength, int weight)
    : Character(std::move(name), health, strength, weight)
{
}