#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include "monster.h"

class Character
{
public:
    Character();
    Character(std::string name,int Hp,int Strength);
    void setName(std::string name);

    int getHp();
    void setHp(int Hp);

    int getStrength();
    void setStrength(int Strength);

    void addMonster(Monster m);
    void replaceMonster(Monster m);


private:
    std::string name;
    int Hp, Strength;
    std::vector<Monster> PlayerMonsters;
};

#endif // CHARACTER_H
