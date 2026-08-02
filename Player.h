//
// Created by David Gonzalez on 7/31/26.
//

#ifndef FORLEARNING_PLAYER_H
#define FORLEARNING_PLAYER_H

#include <vector>
#include <string>
#include "Item.h"

class Player
{
public:
    Player(std::string name, int health, int strength, int weight);
    void playerPickupItem(Item& item);
    void playerDropItem(int backpackSlot);
    void playerTakeDamage(int damageTaken);
    [[nodiscard]] int playerDealDamage(const Item& item) const;

    [[nodiscard]] int getPlayerHealth() const {return playerHealth;}
    [[nodiscard]] int getPlayerMaxWeight() const {return playerMaxWeight;}
    [[nodiscard]] int getPlayerCurrentWeight() const {return playerCurrentWeight;}
    [[nodiscard]] int getPlayerStrength() const {return playerStrength;}
    [[nodiscard]] std::string getPlayerName() const {return playerName;}
    void getPlayerItem(int backpackSlot) const;
    void getPlayerBackpackContents() const;

private:
    Item hands{"Bare Hands", Item::Rarity::white, 5, 0};
    Item empty{"Empty", Item::Rarity::none, 0, 0};

    std::string playerName;
    int playerHealth = 100;
    int playerStrength = 10;
    int playerMaxWeight = 50;
    int maxPlayerHealth = 200;
    int playerCurrentWeight = 0;
    std::vector<Item> backpack = {hands};
};

#endif //FORLEARNING_PLAYER_H