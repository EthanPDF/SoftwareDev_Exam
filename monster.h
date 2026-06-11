#ifndef MONSTER_H
#define MONSTER_H
#include <string>

class Monster
{
public:
    Monster();
    Monster(std::string Name, int Hp, int Strength);

    int getHp();
    void setHp(int Hp);

    int getStrength();

    int getMaxHp();

    std::string getName();

private:
    std::string Name;
    int Hp;
    int Strength;
    int maxHp;

};

#endif // MONSTER_H
