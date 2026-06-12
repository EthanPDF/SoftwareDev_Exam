#ifndef CAVE_H
#define CAVE_H

#include "monster.h"
#include "item.h"
#include <vector>

class Character;

class Cave
{
public:
    Cave(std::vector<Monster> Monsters, Item Reward);

    bool startCave(Character& Player);
    Item getReward();

    void printMonsters();

private:
    std::vector<Monster> Monsters;

    Item Reward;
};

#endif // CAVE_H
