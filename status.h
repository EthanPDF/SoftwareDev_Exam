#ifndef STATUS_H
#define STATUS_H
#include <string>

class Status
{
public:
    Status(std::string Type, int Damage, int Duration, int Chance);

    void turnStart(int &Hp, bool &SkipTurn);
    void onAttack(int &Hp, bool &SkipTurn);
    void tick();

    bool isExpired();

private:
    std::string Type;

    int Damage, Duration, Chance;

};

#endif // STATUS_H
