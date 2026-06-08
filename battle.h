#ifndef BATTLE_H
#define BATTLE_H
#include "character.h"
#include "monster.h"

class Battle
{
public:
    Battle();
    bool startBattle(Character& c, Monster*& playerMonster, Monster& m);

    void attackPhase(Character& c, Monster*& playerMonster, Monster& m, int turn);

    bool isDefeated(Character& c);
    bool monsterDefeated(Monster& m);
};

#endif // BATTLE_H
