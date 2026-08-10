#include <iostream>
#include <thread>
#include "Item.h"
#include "Character.h"
#include "Player.h"
#include "potion.h"
#include "Sword.h"
#include "Store.h"

int main()
{

    Player player("Bob", 100, 10, 75);
    Character enemy("Hobgoblin", 100, 10, 75);
    Store store;

    auto potion = std::make_unique<Potion>("Health Potion", Item::Rarity::gold, 2, 4);
    auto orb = std::make_unique<Item>("Orb of dismay", Item::ItemType::none, Item::Rarity::gold, 10);
    auto sword = std::make_unique<Sword>("Sword of yo momma", Item::Rarity::purple, 10, 45);
    auto sword1 = std::make_unique<Sword>("Sword", Item::Rarity::purple, 10, 45);
    auto shield = std::make_unique<Item>("Shield", Item::ItemType::shield, Item::Rarity::white, 100);
    auto shield1 = std::make_unique<Item>("Shield", Item::ItemType::shield, Item::Rarity::white, 100);


    store.addItem(std::move(sword));
    store.addItem(std::move(shield));
    store.addItem(std::move(potion));
    store.addItem(std::move(shield1));


    std::string playerName;
    std::cout << "Enter player name: ";
    std::getline(std::cin, playerName);

    player.setName(std::move(playerName));
    std::cout << player.getName() << "\n\n";

    int selection = 0;
    while (true)
    {
        std::cout << "Pick a weapon (-1 to exit):\n\n";
        store.listItems();

        std::cout << "Selection: ";
        std::cin >> selection;

        if(selection == -1)
            break;

        std::unique_ptr<Item> purchasedItem = std::move(store.purchaseItem(selection));
        if (purchasedItem == nullptr)
        {
           std::cout << "Item is sold out!\n\n";
            continue;
        }
        player.pickupItem(std::move(purchasedItem));
    }

    std::cout << "You have exited the store.";
    std::cout << player.getCurrentWeight();
}
