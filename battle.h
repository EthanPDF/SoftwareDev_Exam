#ifndef BATTLE_H
#define BATTLE_H
#include "character.h"
#include "monster.h"

class Battle
{
public:
    Battle();
    void startBattle(Character c, Monster m);

    void chooseTurn();
    void attackPhase();

    bool isDefeated();
    bool monsterDefeated();
};

#endif // BATTLE_H
