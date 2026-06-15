#include "character.h"
#include <iostream>

Character::Character(){}

Character::Character(std::string Name,int Hp,int Strength){
    this -> Name = Name;
    this -> Hp = Hp;
    this -> Strength = Strength;
    this -> MaxHp = Hp;
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

void Character::addMonster(Monster M){
    M.resetStatus();

    if(PlayerMonsters.size() < 4){
        PlayerMonsters.push_back(M);
    } else{
        std::cout << "Max limit reached, replace a monster\n";
        replaceMonster(M);
    }
}
void Character::replaceMonster(Monster M){
    for(int i =0; i < PlayerMonsters.size(); i++){
        std::cout << i << ": " << PlayerMonsters[i].getName() << "\n";
    }

    int choice;
    std::cout << "Which monster to replace? ";
    std::cin >> choice;
    if (choice >= 0 && choice < PlayerMonsters.size()){
        PlayerMonsters[choice] = M;
    } else{
        std::cout << "Invalid \n";
    }

}

Monster& Character::getMonster(){ //Gets a monster to fight with
    for(int i =0; i < PlayerMonsters.size(); i++){
        std::cout << i << ": " << PlayerMonsters[i].getName() << ", Hp: " <<
            PlayerMonsters[i].getHp() << ", Items:\n";

        PlayerMonsters[i].printItems();
        std::cout << "\n";
    }

    int choice;

    while(true){
        std::cout << "Which monster to fight with?\n";
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

void Character::resetHp(){ //Reset Hp of Character and Monsters
    Hp = MaxHp;

    for(int i = 0; i < PlayerMonsters.size(); i++){
        PlayerMonsters[i].setHp(PlayerMonsters[i].getMaxHp());
    }
}

int Character::getLevel(){
    int Total = 0;

    for(int i = 0; i < PlayerMonsters.size(); i++){
        Total += PlayerMonsters[i].getStrength();
    }

    return Total / PlayerMonsters.size();
}

void Character::giveItemToMonster(Item Item){
    for(int i = 0; i < PlayerMonsters.size(); i++){
        std::cout << i << ": " << PlayerMonsters[i].getName() << "\n";
    }

    int Choice;
    std::cout << "Choose monster to give item:\n";
    std::cin >> Choice;

    if(Choice >= 0 && Choice < PlayerMonsters.size()){
        PlayerMonsters[Choice].addItem(Item);

        std::cout << Item.getName()
                  << " given to "
                  << PlayerMonsters[Choice].getName()
                  << "\n";
    }
    else {
        std::cout << "Invalid choice\n";
    }
}

int Character::getId() {
    return Id;
}

void Character::setId(int Id) {
    this->Id = Id;
}
