//
// Created by David Gonzalez on 8/9/26.
//

#ifndef CPP_CONSOLE_RPG_BACKPACK_H
#define CPP_CONSOLE_RPG_BACKPACK_H

#include <vector>
#include <memory>
#include "Item.h"

class Backpack
{
public:

    [[nodiscard]] size_t size() const;
    void stashItem(std::unique_ptr<Item> item, size_t backpackSlot = 0);
    std::unique_ptr<Item> equipItem(size_t backpackSlot);
    std::unique_ptr<Item> dropItem(size_t backpackSlot);
    void getItem(size_t backpackSlot) const;
    void getBackpackContents() const;


private:
    std::vector<std::unique_ptr<Item>> backpack;
};


#endif //CPP_CONSOLE_RPG_BACKPACK_H