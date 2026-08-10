//
// Created by David on 8/9/2026.
//

#ifndef CPP_CONSOLE_RPG_STORE_H
#define CPP_CONSOLE_RPG_STORE_H
#include "Backpack.h"


class Store
{
public:
    size_t size() const;
    void addItem(std::unique_ptr<Item> item);
    void listItems() const;
    std::unique_ptr<Item> purchaseItem(size_t storeSlot);

private:
    Backpack storeItems;
};


#endif //CPP_CONSOLE_RPG_STORE_H
