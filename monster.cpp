#include "monster.h"

Monster::Monster() {
}

Monster::Monster(std::string Name, int Hp, int Strength){
    this -> Name = Name;
    this -> Hp = Hp;
    this -> Strength = Strength;
    this -> MaxHp = Hp;
}

int Monster::getHp(){
    return Hp;
}

void Monster::setHp(int Hp){
    this->Hp = Hp;
}

void Monster::addItem(Item Item){
    Items.push_back(Item);
}

void Monster::useItem(int Index){
    if(Index >= 0 && Index < Items.size()){
        Status newStatus = Items[Index].use();
        Statuses.push_back(newStatus);
    }
}

void Monster::applyStatusEffect(bool &SkipTurn){
    for(int i =0; i < Statuses.size(); i++){
        Statuses[i].turnStart(Hp, SkipTurn);
        Statuses[i].tick();

        if(Statuses[i].isExpired()){
            Statuses.erase(Statuses.begin() + i);
            i--;
        }
    }
}

void Monster::triggerOnAttack(bool &SkipTurn){
    for(int i = 0; i < Statuses.size(); i++){
        Statuses[i].onAttack(Hp, SkipTurn);
    }
}

int Monster::getStrength(){
    return Strength;
}

int Monster::getMaxHp(){
    return MaxHp;
}

std::string Monster::getName(){
    return Name;
}
