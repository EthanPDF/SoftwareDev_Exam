#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include "monsters.h"

class Character
{
public:
    Character();
    void attack(Monsters m);
    void takDamage(int dmg);
    void addMonster(Monsters m);
    void replaceMonster(Monsters m);

private:
    int HP, Strength;
    std::vector<Monsters> PlayerMonsters;
};

#endif // CHARACTER_H
