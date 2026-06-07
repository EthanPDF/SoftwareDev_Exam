#include "game.h"
#include <iostream>

Game::Game() {
    Player = Character("",0,0);

    MonstersInGame.push_back(Monster("Horse",4,1)); //Monster initialized with Name, Hp, strength
    MonstersInGame.push_back(Monster("WeakGoblin",4,2));
    MonstersInGame.push_back(Monster("Warrior Goblin",8,3));
    MonstersInGame.push_back(Monster("Goblin General",10,4));
    MonstersInGame.push_back(Monster("Goblin king",15,5));
    MonstersInGame.push_back(Monster("Bandit",20,8));
    MonstersInGame.push_back(Monster("Ogres",30,10));
    MonstersInGame.push_back(Monster("Dragon",100,11));
}


bool Game::startWithMonsters(){
    std::cout << "Start with 2 horses? y/n";
    std::string Choice;
    std::cin >> Choice;
    if(Choice == "y"){
        return true;
    } else {
        return false;
    }
}

void Game::createCharacter(){
    std::string Name;
    int Hp, Strength;

    std::cout << "Choose a name: ";
    std::cin >> Name;

    std::cout << "Choose Hp (Recommended 10): ";
    std::cin >> Hp;

    std::cout << "Choose Strength (Recommended 1): ";
    std::cin >> Strength;

    Player = Character(Name, Hp, Strength);
    if(startWithMonsters()){
        Player.addMonster(Monster("Horse",4,1));
        Player.addMonster(Monster("Horse",4,1));
    }
}

void leave(){
    std::cout << "Leave? (y/n)";
    std::string Leave;
    std::cin >> Leave;
    if(Leave == "y"){
        return;
    } else{
        std::cout << "Continuing game";
    }

}
Monster Game::chooseMonster(){
    for(int i =0; i < MonstersInGame.size(); i++){
        std::cout << i << ": " << MonstersInGame[i].getName() << "\n";
    }

    int Choice;
    std::cout << "Choose a monster to fight";
    std::cin >> Choice;

    return MonstersInGame[Choice];
}

void Game::fight(){
    Monster Chosen = chooseMonster();

    Battle battle;

    bool PlayerWon = battle.startBattle(Player, Chosen);

    if(PlayerWon){
        std::cout << "You win!\n";
        std::cout << "Add monster? (y/n)";
        std::string AddMonster;
        std::cin >> AddMonster;
        if(AddMonster == "y"){
            Player.addMonster(Chosen);
        }
    }
}


bool Game::allMonstersDefeated(){
    for(int i=0; i < MonstersInGame.size(); i++){
        if(MonstersInGame[i].getHp() > 0){
            return false;
        }
    }
    return true;
}
