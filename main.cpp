#include <iostream>
#include "Item.h"
#include "Character.h"
#include "Player.h"
#include "potion.h"

int main()
{

    Player player("Bob", 100, 75, 75);
    Player enemy("Hobgoblin", 100, 75, 75);

    auto potion = std::make_unique<Potion>("Health Potion", Item::Rarity::gold, 2, 4);
    auto orb = std::make_unique<Item>("Orb of dismay", Item::ItemType::none, Item::Rarity::gold, 10);

    auto sword = std::make_unique<Item>("Sword", Item::ItemType::sword, Item::Rarity::purple, 10);
    auto shield = std::make_unique<Item>("Shield", Item::ItemType::shield, Item::Rarity::white, 10);

    std::cout << "Player Name: " << player.getName() << "\n\n";

    player.takeDamage(enemy);
    enemy.takeDamage(player);



}