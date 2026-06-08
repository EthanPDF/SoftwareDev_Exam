#include "battle.h"
#include <iostream>
#include <cstdlib>

Battle::Battle() {}

bool Battle::startBattle(Character& c, Monster*& playerMonster, Monster& m){
    std::cout << "Battle start\n";
    std::cout << c.getName() << " vs " << m.getName() << "\n";

    int turn = rand() % 2;



    while(true){
        attackPhase(c, playerMonster, m, turn);
        if(monsterDefeated(m)){
            std::cout << m.getName() << " is defeated! \n";
            return true;
        }
        if(isDefeated(c)){
            std::cout << c.getName() << " is defeated! You lose\n";
            return false;
        }
        turn = 1 - turn;
    }
}


void Battle::attackPhase(Character& c, Monster*& playerMonster, Monster& m, int turn){

    if (turn == 0) {
        if(c.checkIfMonstersDead()){
            int dmg = c.getStrength();
            m.setHp(m.getHp()-dmg);
            std::cout << c.getName() << " dealt " << dmg << " dmg\n";

        }else if(playerMonster->getHp()<=0){ //Swap monster after death
            std::cout << "Return: " << playerMonster->getName() << "!\n";
            playerMonster = &c.getMonster();
            std::cout << "Come out: " << playerMonster->getName() << "!\n";

        } else { //Regular attack
        int dmg = playerMonster->getStrength();
        m.setHp(m.getHp() - dmg);

        std::cout << c.getName() << "'s Monster: " << playerMonster->getName()
                  << " dealt " << dmg << " dmg\n";
        }

    } else {
        int dmg = m.getStrength();

        if (playerMonster->getHp() > 0) {
            // attack player's monster
            playerMonster->setHp(playerMonster->getHp() - dmg);

            std::cout << m.getName()
                      << " dealt " << dmg
                      << " dmg to " << playerMonster->getName() << "\n";
        } else {
            c.setHp(c.getHp() - dmg);

            std::cout << m.getName()
                      << " dealt " << dmg
                      << " dmg to " << c.getName() << "\n";
        }
    }
}

bool Battle::isDefeated(Character& c){
    return c.getHp() <= 0;
}

bool Battle::monsterDefeated(Monster& m){
    return m.getHp() <= 0;
}
