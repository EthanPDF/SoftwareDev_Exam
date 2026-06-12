#include "status.h"
#include <iostream>
#include <cstdlib>

Status::Status(std::string Type, int Damage, int Duration, int Chance)
    :  Type(Type), Damage(Damage), Duration(Duration), Chance(Chance) {}

void Status::turnStart(int &Hp, bool &SkipTurn){
    if(Type == "poison"){
        Hp -= Damage;
    } else if(Type == "heal"){
        Hp += Damage;
    } else if(Type == "freeze"){
        int roll = rand() % 100;

        if(roll < Chance){
            SkipTurn = true;
            std::cout << "Monster is frozen!\n";
        }
    }
}

void Status::onAttack(int &Hp, bool &SkipTurn){
    if(Type == "cursed"){
        Hp -= Damage;
        std::cout << "Monster is cursed! Monster takes: " << Damage << " Damage\n";
    } else if(Type == "paralyzed"){
        int roll = rand()%100;

        if(roll < Chance){
            SkipTurn = true;
            std::cout << "Monster is paralyzed! Monster cant attack!\n";
        }
    }
}

void Status::tick(){
    Duration--;
}

bool Status::isExpired(){
    return Duration <= 0;
}
