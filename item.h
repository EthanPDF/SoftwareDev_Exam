#ifndef ITEM_H
#define ITEM_H

#include "statuseffect.h"
#include <string>

class Item
{
public:
    Item(std::string Name, StatusEffect Effect);

    Status use();

    std::string getName();

private:
    std::string Name;

    StatusEffect Effect;

};

#endif // ITEM_H
