//
// Created by David Gonzalez on 8/5/26.
//

#include "Potion.h"
#include "Character.h"

    Potion::Potion(std::string name, Rarity rarity, int weight, int effectAmount)
        : Item(std::move(name), ItemType::potion, rarity, weight), potionEffectAmount(effectAmount) {}

    void Potion::itemEffects(Character& character)
    {
        if (character.getHealth() == 0)
        {
            std::cout << "Cannot heal as " << character.getName() << " is dead!\n\n";
            return;
        }

        if (character.getHealth() == character.getMaxHealth())
        {
            std::cout << character.getName() << " is already at max health!\n\n";
            return;
        }

        if (potionEffectAmount + character.getHealth() > character.getMaxHealth())
            potionEffectAmount = character.getMaxHealth() - character.getHealth();

        character.setHealth(character.getHealth() + potionEffectAmount);
        std::cout << character.getName() << " healed by " << potionEffectAmount << " points" << std::endl;
        std::cout << "Current Health: " << character.getHealth() << "\n\n";
    }