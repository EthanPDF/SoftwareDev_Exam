#include "item.h"

Item::Item(std::string Name, StatusEffect Effect)
    : Name(Name), Effect(Effect) {}

Status Item::use(){
    return Effect.createStatus();
}
