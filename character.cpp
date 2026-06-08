#include "character.h"
#include <iostream>

Character::Character(){}

Character::Character(std::string Name,int Hp,int Strength){
    this -> Name = Name;
    this -> Hp = Hp;
    this -> Strength = Strength;
}

void Character::setName(std::string Name){
    this -> Name = Name;
}

std::string Character::getName(){
    return Name;
}

int Character::getHp(){
    return Hp;
}

void Character::setHp(int Hp){
    this -> Hp = Hp;
}

int Character::getStrength(){
    return Strength;
}

void Character::setStrength(int Strength){
    this -> Strength = Strength;
}

void Character::addMonster(Monster m){
    if(PlayerMonsters.size() < 4){
        PlayerMonsters.push_back(m);
    } else{
        std::cout << "Max limit reached, replace a monster\n";
        replaceMonster(m);
    }
}
void Character::replaceMonster(Monster m){
    for(int i =0; i < PlayerMonsters.size(); i++){
        std::cout << i << ": " << PlayerMonsters[i].getName() << "\n";
    }

    int choice;
    std::cout << "Which monster to replace? ";
    std::cin >> choice;
    if (choice >= 0 && choice < PlayerMonsters.size()){
        PlayerMonsters[choice] = m;
    } else{
        std::cout << "Invalid \n";
    }

}

Monster& Character::getMonster(){
    for(int i =0; i < PlayerMonsters.size(); i++){
        std::cout << i << ": " << PlayerMonsters[i].getName() << "\n";
    }

    int choice;

    while(true){
        std::cout << "Which monster to fight with? ";
        std::cin >> choice;

        if(choice >= 0 && choice < PlayerMonsters.size()){
            return PlayerMonsters[choice];
        } else{
            std::cout << "Invalid\n";
        }
    }
}

bool Character::checkIfMonstersDead(){

    for(int i = 0; i < PlayerMonsters.size(); i++){
        if(PlayerMonsters[i].getHp() > 0){
            return false;
        }
    }
    return true;
}
