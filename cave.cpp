#include "cave.h"
#include "battle.h"

Cave::Cave(std::vector<Monster> Monsters, Item Reward)
    : Monsters(Monsters), Reward(Reward) {}

bool Cave::startCave(Character & Player){
    Battle Battle;

    for(int i = 0; i < Monsters.size(); i++){
        Monster* Chosen = &Player.getMonster();

        bool won = Battle.startBattle(Player, Chosen, Monsters[i]);

        if(!won){
            return false;
        }
    }
    return true;
}

Item Cave::getReward(){
    return Reward;
}
