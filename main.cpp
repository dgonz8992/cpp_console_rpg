#include <iostream>
#include "Item.h"
#include "Character.h"
#include "Player.h"
#include "potion.h"

int main()
{
    Player player("Bob", 100, 10, 75);
    Potion potion("Health Potion", Item::Rarity::gold, 2, 4);
    Item orb("Orb of dismay", Item::ItemType::none, Item::Rarity::gold, 10);

    Item sword("Sword", Item::ItemType::sword, Item::Rarity::purple, 10);
    Item shield("Shield", Item::ItemType::shield, Item::Rarity::white, 10);

    std::cout << "Player Name: " << player.getName() << "\n\n";

    player.takeDamage(0);
    player.useItem(potion);
    player.useItem(orb);

}