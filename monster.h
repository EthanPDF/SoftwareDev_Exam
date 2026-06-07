#ifndef MONSTER_H
#define MONSTER_H
#include <string>

class Monster
{
public:
    Monster();
    Monster(std::string name, int HP, int Strength);

    int getHP();
    int setHp();

    int getStrength();

    std::string getName();

private:
    std::string name;
    int HP;
    int Strength;
};

#endif // MONSTER_H
