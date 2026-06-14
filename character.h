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

    void addMonster(Monster M);
    void replaceMonster(Monster M);
    Monster& getMonster();

    bool checkIfMonstersDead();

    void resetHp();

    int getLevel(); //2. iteration
    void giveItemToMonster(Item Item); //2. iteration

    int getId(); //3. iteration
    void setId(int Id); //3. iteration



private:
    std::string Name;
    int Hp, Strength, MaxHp, Id;
    std::vector<Monster> PlayerMonsters;
};

#endif // CHARACTER_H
