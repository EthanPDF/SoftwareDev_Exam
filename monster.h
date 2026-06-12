#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include "item.h"
#include <vector>

class Monster
{
public:
    Monster();
    Monster(std::string Name, int Hp, int Strength);

    int getHp();
    void setHp(int Hp);
    void addItem(Item Item);
    void useItem(int Index);
    void applyStatusEffect(bool &SkipTurn);
    void triggerOnAttack(bool &SkipTurn);

    int getStrength();

    int getMaxHp();

    std::string getName();

private:
    std::string Name;
    int Hp, Strength, MaxHp;
    std::vector<Status> Statuses;
    std::vector<Item> Items;

};

#endif // MONSTER_H
