#ifndef BATTLE_H
#define BATTLE_H
#include "character.h"
#include "monster.h"
#include "database.h"

class Battle
{
public:
    Battle();
    bool startBattle(Character& C, Monster*& PlayerMonster, Monster& M, Database& db);

    void attackPhase(Character& C, Monster*& PlayerMonster, Monster& M, int Turn, Database& db);

    bool isDefeated(Character& C);
    bool monsterDefeated(Monster& M);
};

#endif // BATTLE_H
