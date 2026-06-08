#ifndef GAME_H
#define GAME_H
#include <vector>
#include "character.h"
#include "monster.h"
#include "battle.h"

class Game
{
public:
    Game();
    bool startWithMonsters();

    void createCharacter();
    void leave();
    void fight();

    Monster& chooseMonster();
    bool allMonstersDefeated();

private:
    Character Player;
    std::vector<Monster> MonstersInGame;

};

#endif // GAME_H
