//
// Created by David on 8/9/2026.
//

#include "Store.h"

size_t Store::size() const
{
    return storeItems.size();
}

void Store::addItem(std::unique_ptr<Item> item)
{
    storeItems.stashItem(std::move(item));
}

void Store::listItems() const
{
    storeItems.getBackpackContents();
}

std::unique_ptr<Item> Store::purchaseItem(size_t storeSlot)
{
    if (storeSlot > storeItems.size())
    {
        std::cout << "Invalid item slot!\n\n";
        return nullptr;
    }

    return storeItems.dropItem(storeSlot - 1);
}