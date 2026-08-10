#include <iostream>
#include <thread>
#include "Item.h"
#include "Character.h"
#include "Player.h"
#include "potion.h"
#include "Sword.h"

int main()
{

    bool running = true;
    Player player("Bob", 100, 10, 75);
    Character  enemy("Hobgoblin", 100, 10, 75);

    auto potion = std::make_unique<Potion>("Health Potion", Item::Rarity::gold, 2, 4);
    auto orb = std::make_unique<Item>("Orb of dismay", Item::ItemType::none, Item::Rarity::gold, 10);

    auto sword = std::make_unique<Sword>("Sword", Item::Rarity::purple, 10, 45);
    auto sword1 = std::make_unique<Sword>("Sword", Item::Rarity::purple, 10, 45);

    auto shield = std::make_unique<Item>("Shield", Item::ItemType::shield, Item::Rarity::white, 10);

    player.pickupItem(std::move(orb));
    player.pickupItem(std::move(sword));
    player.pickupItem(std::move(potion));

    enemy.pickupItem(std::move(sword1));
    enemy.equipItem(0);

    player.takeDamage(enemy);

    player.getItem(0);
    player.useItem(2);
}