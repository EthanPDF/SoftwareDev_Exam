#include "statuseffect.h"

StatusEffect::StatusEffect(std::string Type, int Damage, int Duration, int Chance)
    : Type(Type), Damage(Damage), Duration(Duration), Chance(Chance) {}

Status StatusEffect::createStatus(){
    return Status(Type, Damage, Duration, Chance);
}

std::string StatusEffect::getType(){
    return Type;
}
