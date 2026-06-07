#include "monster.h"

Monster::Monster() {
}

Monster::Monster(std::string Name, int Hp, int Strength){
    this -> Name = Name;
    this -> Hp = Hp;
    this -> Strength = Strength;
}

int Monster::getHp(){
    return Hp;
}

void Monster::setHp(int Hp){
    this->Hp = Hp;
}

int Monster::getStrength(){
    return Strength;
}

std::string Monster::getName(){
    return Name;
}
