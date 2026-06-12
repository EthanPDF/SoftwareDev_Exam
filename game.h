#ifndef GAME_H
#define GAME_H
#include <vector>
#include "character.h"
#include "monster.h"
#include "cave.h"


class Game
{
public:
    Game();
    bool startWithMonsters();
    bool leave();

    void resetEnemies();
    void createCharacter();
    void fight();

    int chooseMonsterIndex();
    bool allMonstersDefeated();

    Cave generateCave();
    void enterCave();

private:
    Character Player;
    std::vector<Monster> MonstersInGame;

};

#endif // GAME_H
