#include "monster.h"
#include <iostream>

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

void Monster::addStatus(Status Status){
    Statuses.push_back(Status);
}

void Monster::useItem(int Index, Monster& Target, bool TargetSelf){
    if(Index >= 0 && Index < Items.size()){
        Status newStatus = Items[Index].use();

        if(TargetSelf){
            addStatus(newStatus);
        } else{
            Target.addStatus(newStatus);
        }

        Items.erase(Items.begin() + Index);
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

void Monster::printItems(){
    for (int i = 0; i < Items.size(); i++) {
        std::cout << i << ": " << Items[i].getName() << "\n";
    }

}

void Monster::resetStatus(){
    Statuses.clear();
}

std::string Monster::getItemType(int Index){

    if(Index >= 0 && Index < Items.size()){
        return Items[Index].getType();
    }
    return "";

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
