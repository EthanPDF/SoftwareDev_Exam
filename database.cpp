#include "database.h"
#include <iostream>

void Database::open() {
    if(sqlite3_open("game.db", &db)){
        std::cout << "Error opening database\n";
    }
}

void Database::savePlayer(Character& Player) {

    std::string Sql =
        "INSERT INTO Player (name, hp, strength) VALUES ('" +
        Player.getName() + "', " +
        std::to_string(Player.getHp()) + ", " +
        std::to_string(Player.getStrength()) + ");";

    sqlite3_exec(db, Sql.c_str(), 0, 0, 0);

    int id = sqlite3_last_insert_rowid(db);

    Player.setId(id);
}

void Database::deletePlayer(int Id) {

    std::string Sql =
        "DELETE FROM Player WHERE id = " + std::to_string(Id) + ";";

    sqlite3_exec(db, Sql.c_str(), 0, 0, 0);

    std::cout << "Player deleted\n";
}

std::vector<Character> Database::loadPlayers() {

    std::vector<Character> Players;

    const char* Sql = "SELECT id, name, hp, strength FROM Player;";

    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, Sql, -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        int id = sqlite3_column_int(stmt, 0);
        std::string Name = (const char*)sqlite3_column_text(stmt, 1);
        int Hp = sqlite3_column_int(stmt, 2);
        int Strength = sqlite3_column_int(stmt, 3);

        Character c(Name, Hp, Strength);
        c.setId(id);

        Players.push_back(c);
    }

    sqlite3_finalize(stmt);

    return Players;
}

void Database::recordMonsterKill(std::string name) {

    std::string Sql =
        "INSERT INTO MonsterKills (monster_name, kill_count) VALUES ('" + name + "', 1) "
                    "ON CONFLICT(monster_name) DO UPDATE SET kill_count = kill_count + 1;";

    sqlite3_exec(db, Sql.c_str(), 0, 0, 0);
}

void Database::recordItemUse(int PlayerId, std::string Type) {

    std::string Sql =
        "INSERT INTO ItemUsage (player_id, item_type, usage_count) VALUES (" +
        std::to_string(PlayerId) + ", '" + Type + "', 1) "
                                                  "ON CONFLICT(player_id, item_type) DO UPDATE SET "
                                                  "usage_count = usage_count + 1;";

    sqlite3_exec(db, Sql.c_str(), 0, 0, 0);
}
