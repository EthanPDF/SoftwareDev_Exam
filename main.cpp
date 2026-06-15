#include <iostream>
#include <ctime>
#include "game.h"
#include "database.h"

int main() {
    std::cout << "Program started!\n" << std::endl;
    srand(time(0));

    Database db;
    db.open();
    db.createTables();

    Game game(db);

    game.createCharacter();

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Fight monsters on plateau\n";
        std::cout << "2. Enter Cave\n";
        std::cout << "3. View Stats\n";
        std::cout << "4. Leave\n";

        int Choice;
        std::cin >> Choice;

        switch(Choice){
        case 1: game.fight(); break;
        case 2: game.enterCave(); break;
        case 3: db.printStats(); break;
        case 4: std::cout << "Goodbye!\n"; return 0; break;
        default: std::cout << "Invalid input\n"; break;
        }
    }
}
