#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include <string>
#include "monster.h"

class Character
{
public:
    Character();
    Character(std::string Name,int Hp,int Strength);
    void setName(std::string Name);
    std::string getName();

    int getHp();
    void setHp(int Hp);

    int getStrength();
    void setStrength(int Strength);

    void addMonster(Monster m);
    void replaceMonster(Monster m);
    Monster& getMonster();

    bool checkIfMonstersDead();


private:
    std::string Name;
    int Hp, Strength;
    std::vector<Monster> PlayerMonsters;
};

#endif // CHARACTER_H
