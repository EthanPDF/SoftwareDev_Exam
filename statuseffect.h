#ifndef STATUSEFFECT_H
#define STATUSEFFECT_H

#include "status.h"
#include <string>

class StatusEffect
{
public:
    StatusEffect(std::string Type, int Damage, int Duration, int Chance);

    Status createStatus();

private:
    std::string Type;

    int Damage, Duration, Chance;
};

#endif // STATUSEFFECT_H
