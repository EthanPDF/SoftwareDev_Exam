#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3.h"
#include <string>
#include "character.h"

class Database {
public:
    void open();
    void createTables();

    void savePlayer(Character& Player);
    void deletePlayer(int Id);

    std::vector<Character> loadPlayers();

    void recordMonsterKill(std::string MonsterName);

    void recordItemUse(int PlayerId, std::string Type);


private:
    sqlite3* db;
};

#endif
