#include "item.h"

Item::Item(std::string Name, StatusEffect Effect)
    : Name(Name), Effect(Effect) {}

Status Item::use(){
    return Effect.createStatus();
}

std::string Item::getName(){
    return Name;
}

std::string Item::getType(){
    return Effect.getType();
}
