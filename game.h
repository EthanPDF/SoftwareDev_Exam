#ifndef GAME_H
#define GAME_H
#include <vector>
#include "character.h"
#include "monster.h"


class Game
{
public:
    Game();
    bool startWithMonsters();
    bool leave();

    void createCharacter();
    void fight();

    Monster& chooseMonster();
    bool allMonstersDefeated();

private:
    Character Player;
    std::vector<Monster> MonstersInGame;

};

#endif // GAME_H
