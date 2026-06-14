#ifndef CAVE_H
#define CAVE_H
#include "database.h"
#include "monster.h"
#include "item.h"
#include <vector>

class Character;

class Cave
{
public:
    Cave(std::vector<Monster> Monsters, Item Reward);

    bool startCave(Character& Player, Database& db);
    Item getReward();

    void printMonsters();

private:
    std::vector<Monster> Monsters;

    Item Reward;
};

#endif // CAVE_H
