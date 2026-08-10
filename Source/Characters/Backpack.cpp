//
// Created by David Gonzalez on 8/9/26.
//

#include "Backpack.h"

size_t Backpack::size() const
{
    return backpack.size();
}

void Backpack::storeItem(std::unique_ptr<Item> item, size_t backpackSlot)
{
    bool slotFilled = false;

    if (backpackSlot < backpack.size())
    {
        if (backpack[backpackSlot] == nullptr)
        {
            backpack[backpackSlot] = std::move(item);
            return;
        }
    }

    for (auto& i : backpack)
    {
        if (i == nullptr)
        {
            i = std::move(item);
            slotFilled = true;
            break;
        }
    }

    if (!slotFilled)
        backpack.push_back(std::move(item));
}

std::unique_ptr<Item> Backpack::equipItem(const size_t backpackSlot)
{
    if (backpackSlot >= backpack.size())
    {
        return nullptr;
    }
    return std::move(backpack[backpackSlot]);
}

std::unique_ptr<Item> Backpack::dropItem(const size_t backpackSlot)
{
    if (backpackSlot >= backpack.size() || backpack[backpackSlot] == nullptr)
        return nullptr;

    return std::move(backpack[backpackSlot]);
}

void Backpack::getItem(const size_t backpackSlot) const
{
    if (backpackSlot >= backpack.size())
        std::cout << "Invalid slot!\n\n";
    else if (backpack[backpackSlot] == nullptr)
        std::cout << "Slot is empty!\n\n";
    else
    {
        std::cout << "Slot " << backpackSlot + 1 << ":\n";
        std::cout << "Name: " << backpack[backpackSlot]->getItemName() << std::endl;
        std::cout << "Strength: " << backpack[backpackSlot]->getItemRarityStrength() << std::endl;
        std::cout << "Rarity: " << backpack[backpackSlot]->getItemRarityColor() << std::endl;
        std::cout << "Weight: " << backpack[backpackSlot]->getItemWeight() << std::endl;
        std::cout << '\n';
    }

}

void Backpack::getBackpackContents() const
{
    std::cout << "Backpack contents: \n";
    for (size_t i = 0; i < backpack.size(); i++)
    {
        if (backpack[i] == nullptr)
        {
            std::cout << "Slot " << i+1 << ":\n";
            std::cout << "Empty\n\n";
            continue;
        }
        std::cout << "Slot " << i+1 << ":\n";
        std::cout << "Name: " << backpack[i]->getItemName() << std::endl;
        std::cout << "Strength: " << backpack[i]->getItemRarityStrength() << std::endl;
        std::cout << "Rarity: " << backpack[i]->getItemRarityColor() << std::endl;
        std::cout << "Weight: " << backpack[i]->getItemWeight() << std::endl;
        std::cout << '\n';
    }
    std::cout << "======================================\n\n";
}
