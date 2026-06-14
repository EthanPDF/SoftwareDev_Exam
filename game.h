#ifndef GAME_H
#define GAME_H
#include <vector>
#include "character.h"
#include "monster.h"
#include "cave.h"
#include "database.h"

class Game
{
public:
    Game(Database& db);
    bool startWithMonsters();
    bool leave();

    void resetEnemies();
    void createCharacter();
    void fight();

    int chooseMonsterIndex();
    bool allMonstersDefeated();

    Cave generateCave(); //2. iteration
    void enterCave(); //2. iteration

private:
    Character Player;
    std::vector<Monster> MonstersInGame;

    Database& db;

};

#endif // GAME_H
