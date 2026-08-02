#include <iostream>
#include "Item.h"
#include "Player.h"

int main()
{
    Player player1("Bob", 100, 10, 75);

    Item sword("Sword", Item::Rarity::purple, 50, 50);
    Item shield("Shield", Item::Rarity::white, 50, 25);

    std::cout << "Player Name: " << player1.getPlayerName() << '\n';

    player1.getPlayerItem(0);
    player1.playerPickupItem(sword);
    player1.playerPickupItem(shield);
    player1.playerTakeDamage(6);
    player1.getPlayerBackpackContents();
    player1.playerDropItem(1);
    player1.getPlayerBackpackContents();

}