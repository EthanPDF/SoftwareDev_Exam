#include "database.h"
#include <iostream>

void Database::open() {
    if(sqlite3_open("game.db", &db)){
        std::cout << "Error opening database\n";
    }
}

void Database::savePlayer(Character& Player) {

    std::string sql =
        "INSERT INTO Player (name, hp, strength) VALUES ('" +
        Player.getName() + "', " +
        std::to_string(Player.getHp()) + ", " +
        std::to_string(Player.getStrength()) + ");";

    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

void Database::deletePlayer(int Id) {

    std::string sql =
        "DELETE FROM Player WHERE id = " + std::to_string(Id) + ";";

    sqlite3_exec(db, sql.c_str(), 0, 0, 0);

    std::cout << "Player deleted\n";
}

std::vector<Character> Database::loadPlayers() {

    std::vector<Character> Players;

    const char* sql = "SELECT name, hp, strength FROM Player;";

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        std::string Name = (const char*)sqlite3_column_text(stmt, 0);
        int hp = sqlite3_column_int(stmt, 1);
        int strength = sqlite3_column_int(stmt, 2);

        Players.push_back(Character(Name, Hp, Strength));
    }

    sqlite3_finalize(stmt);

    return Players;
}

void Database::recordMonsterKill(std::string MonsterName) {

    std::string sql =
        "INSERT INTO MonsterKills (monster_name, kill_count) VALUES ('" +
        MonsterName + "', 1);";

    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

void Database::recordItemUse(std::string Type) {

    std::string sql =
        "INSERT INTO ItemUsage (item_type, usage_count) VALUES ('" +
        type + "', 1);";

    sqlite3_exec(db, sql.c_str(), 0, 0, 0);

    std::cout << "Item use recorded: " << Type << "\n";
}
