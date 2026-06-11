#include "battle.h"
#include <iostream>
#include <cstdlib>

Battle::Battle() {}

bool Battle::startBattle(Character& c, Monster*& PlayerMonster, Monster& m){
    std::cout << "Battle start\n";
    std::cout << c.getName() << " vs " << m.getName() << "\n";

    int Turn = rand() % 2;



    while(true){
        attackPhase(c, PlayerMonster, m, Turn);
        if(monsterDefeated(m)){
            std::cout << m.getName() << " is defeated! \n";
            return true;
        }
        if(isDefeated(c)){
            std::cout << c.getName() << " is defeated! You lose\n";
            return false;
        }
        Turn = 1 - Turn;
    }
}


void Battle::attackPhase(Character& c, Monster*& PlayerMonster, Monster& m, int Turn){

    if (Turn == 0) {
        if(c.checkIfMonstersDead()){
            int Dmg = c.getStrength();
            m.setHp(m.getHp() - Dmg);
            std::cout << c.getName() << " dealt " << Dmg << " dmg\n";

        }else if(PlayerMonster->getHp()<=0){ //Swap monster after death
            std::cout << PlayerMonster->getName() << " Has been defeated!";

            std::cout << "Return: " << PlayerMonster->getName() << "!\n";
            PlayerMonster = &c.getMonster();
            std::cout << "Come out: " << PlayerMonster->getName() << "!\n";

        } else { //Regular attack
        int Dmg = PlayerMonster->getStrength();
        m.setHp(m.getHp() - Dmg);

        std::cout << c.getName() << "'s Monster: " << PlayerMonster->getName()
                  << " dealt " << Dmg << " dmg\n";
        }

    } else {
        int Dmg = m.getStrength();

        if (PlayerMonster->getHp() > 0) {
            // attack player's monster
            PlayerMonster->setHp(PlayerMonster->getHp() - Dmg);

            std::cout << m.getName()
                      << " dealt " << Dmg
                      << " dmg to " << PlayerMonster->getName() << "\n";
        } else {
            c.setHp(c.getHp() - Dmg);

            std::cout << m.getName()
                      << " dealt " << Dmg
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
