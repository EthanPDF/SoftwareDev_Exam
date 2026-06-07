#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>
#include "monster.h"

class Character
{
public:
    Character();
    Character(std::string name,int HP,int Strength);
    void setName(std::string name);

    int getHP();
    int setHP();
    int getStrength();
    int setStrength();

    void addMonster(Monster m);
    void replaceMonster(Monster m);


private:
    std::string name;
    int HP, Strength;
    std::vector<Monster> PlayerMonsters;
};

#endif // CHARACTER_H
