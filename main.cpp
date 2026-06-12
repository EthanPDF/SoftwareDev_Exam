#include <iostream>
#include <ctime>
#include "game.h"

int main() {
    srand(time(0));

    Game game;
    game.createCharacter();

    while (true) {
        std::cout << "\n--- MENU ---\n";
        std::cout << "1. Fight monsters on plateau\n";
        std::cout << "2. Enter Cave\n";
        std::cout << "3. Leave\n";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            game.fight();
        }
        else if (choice == 2) {
            game.enterCave();
        }
        else if (choice == 3) {
            std::cout << "Goodbye!\n";
            break;
        }
        else {
            std::cout << "Invalid input\n";
        }

        if (game.allMonstersDefeated()) {
            std::cout << "\nYou defeated all enemies! You win!\n";
            break;
        }
    }

    return 0;
}
