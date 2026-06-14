#include "battle.h"
#include <iostream>
#include <cstdlib>

Battle::Battle() {}

bool Battle::startBattle(Character& C, Monster*& PlayerMonster, Monster& M, Database& db){

    std::cout << "Battle start\n";
    std::cout << C.getName() << " vs " << M.getName() << "\n";

    int Turn = rand() % 2;



    while(true){
        attackPhase(C, PlayerMonster, M, Turn, db);

        if(monsterDefeated(M)){
            std::cout << M.getName() << " is defeated! \n";
            return true;
        }
        if(isDefeated(C)){
            std::cout << C.getName() << " is defeated! You lose\n";
            return false;
        }
        Turn = 1 - Turn;
    }
}


void Battle::attackPhase(Character& C, Monster*& PlayerMonster, Monster& M, int Turn, Database& db){
    if (Turn == 0) {
        bool SkipTurn = false;
        PlayerMonster->applyStatusEffect(SkipTurn);

        if(SkipTurn){
            std::cout <<PlayerMonster->getName() << " skips turn!\n";
            return;
        }

        if(C.checkIfMonstersDead()){
            int Dmg = C.getStrength();
            M.setHp(M.getHp() - Dmg);
            std::cout << C.getName() << " dealt " << Dmg << " dmg\n";
            return;

        }

        if(PlayerMonster->getHp()<=0){ //Swap monster after death
            std::cout << PlayerMonster->getName() << " Has been defeated!\n";

            std::cout << "Return: " << PlayerMonster->getName() << "!\n";
            PlayerMonster = &C.getMonster();
            std::cout << "Come out: " << PlayerMonster->getName() << "!\n";
        }

        //Regular attack
            std::cout << "1: Attack\n2: Use Item\n";
            int Choice;
            std::cin >> Choice;

        if(Choice == 1){

            PlayerMonster->triggerOnAttack(SkipTurn);
            if(SkipTurn){
                std::cout << "Attack prevented!\n";
                return;
                }

            int Dmg = PlayerMonster->getStrength();
            M.setHp(M.getHp() - Dmg);
            std::cout << C.getName() << "'s Monster: " << PlayerMonster->getName()
                        << " dealt " << Dmg << " dmg\n";

            } else if(Choice == 2){
                int ItemIndex;
                PlayerMonster->printItems();
                std::cin >> ItemIndex;

                std::string Type = PlayerMonster->getItemType(ItemIndex);

                if(Type == "heal"){
                    PlayerMonster->useItem(ItemIndex, M, true);
                } else{
                   PlayerMonster->useItem(ItemIndex, M, false);
                }

                db.recordItemUse(Type);

                std::cout << "Item Used!\n";
            }

    } else {
        bool SkipTurn = false;

        M.applyStatusEffect(SkipTurn);

        if(SkipTurn){
            std::cout << M.getName() << " skips turn!\n";
            return;
        }

        int Dmg = M.getStrength();
        M.triggerOnAttack(SkipTurn);
        if(SkipTurn){
            std::cout << M.getName() << " skips turn!\n";
            return;
        }

        if (PlayerMonster->getHp() > 0) {
            // attack player's monster
            PlayerMonster->setHp(PlayerMonster->getHp() - Dmg);

            std::cout << M.getName()
                      << " dealt " << Dmg
                      << " dmg to " << PlayerMonster->getName() << "\n";
        } else {
            C.setHp(C.getHp() - Dmg);

            std::cout << M.getName()
                      << " dealt " << Dmg
                      << " dmg to " << C.getName() << "\n";
        }
    }
}

bool Battle::isDefeated(Character& C){
    return C.getHp() <= 0;
}

bool Battle::monsterDefeated(Monster& M){
    return M.getHp() <= 0;
}
