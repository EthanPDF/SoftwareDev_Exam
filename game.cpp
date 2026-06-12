#include "game.h"
#include <iostream>
#include "battle.h"

Game::Game() {
    Player = Character("",0,0);

    resetEnemies();

}


bool Game::startWithMonsters(){
    std::cout << "Start with 2 horses? y/n ";
    std::string Choice;
    std::cin >> Choice;
    if(Choice == "y"){
        return true;
    } else {
        return false;
    }
}

void Game::resetEnemies(){//Resets monsters in game

    MonstersInGame.clear();

    MonstersInGame.push_back(Monster("Horse",4,1)); //Monster initialized with Name, Hp, strength
    MonstersInGame.push_back(Monster("WeakGoblin",4,2));
    MonstersInGame.push_back(Monster("Warrior Goblin",8,3));
    MonstersInGame.push_back(Monster("Goblin General",10,4));
    MonstersInGame.push_back(Monster("Goblin king",15,5));
    MonstersInGame.push_back(Monster("Bandit",20,8));
    MonstersInGame.push_back(Monster("Ogres",30,10));
    MonstersInGame.push_back(Monster("Dragon",100,11));
}

void Game::createCharacter(){
    std::string Name;
    int Hp, Strength;

    std::cout << "Choose a name: ";
    std::cin >> Name;

    Hp =10;
    Strength = 1;

    Player = Character(Name, Hp, Strength);
    if(startWithMonsters()){
        Player.addMonster(Monster("Horse",4,1));
        Player.addMonster(Monster("Horse",4,1));
    }
}

bool Game::leave(){

    std::cout << "Leave? (y/n): ";

    std::string Choice;
    std::cin >> Choice;


    if(Choice == "y"){
    return true;
    } else{
        return false;
    }

}
int Game::chooseMonsterIndex(){ //Chooses a monster (But returns an int value which is position of chosen monster)

    for(int i = 0; i < MonstersInGame.size(); i++){
        std::cout << i << ": " << MonstersInGame[i].getName() << "\n";
    }

    int Choice;

    while (true) {
        std::cout << "Choose a monster: ";
        std::cin >> Choice;

        if (Choice >= 0 && Choice < MonstersInGame.size()) {
            return Choice;
        } else {
            std::cout << "Invalid choice\n";
        }
    }

}

void Game::fight(){ //Fight method, uses the battle logic to start and fight fights

    std::cout << "What enemy to fight? ";
    int index = chooseMonsterIndex();
    Monster& Enemy = MonstersInGame[index];
    std::cout << "Which monster to fight with? ";
    Monster* PlayerChosen = &Player.getMonster();

    Battle battle;

    bool PlayerWon = battle.startBattle(Player, PlayerChosen, Enemy);

    if(PlayerWon){
        std::cout << "You win!\n";

        std::cout << "Hp reset!\n";

        std::cout << "Add monster? (y/n)";
        std::string AddMonster;
        std::cin >> AddMonster;
        if(AddMonster == "y"){
            Player.addMonster(Enemy);
        }
        MonstersInGame.erase(MonstersInGame.begin() + index); //Erase monster after adding it, or not
    } else{ //If defeated
        std::cout << "You lost!\n" << "Restarting...\n";
        resetEnemies();
        createCharacter();
    }
    Player.resetHp();
}


bool Game::allMonstersDefeated(){
    for(int i=0; i < MonstersInGame.size(); i++){
        if(MonstersInGame[i].getHp() > 0){
            return false;
        }
    }
    return true;
}

Cave Game::generateCave(){
    int Level = Player.getLevel();

    std::vector<Monster> CaveMonsters;

    int numMonsters = 2 + (Level / 4);

    for(int i = 0; i < numMonsters; i++){

        int Hp = 5 + (Level * 2);
        int Strength = Level;

        CaveMonsters.push_back(Monster("caveMonster", Hp, Strength));
    }

    //Random reward generator below
    std::vector<std::string> Types = {
        "poison", "heal", "freeze", "cursed", "paralyzed"
    };

    int index = rand() % Types.size();
    std::string chosenType = Types[index];

    int damage = 0;
    int duration = 0;
    int chance = 100;

    if (chosenType == "poison") {
        damage = 2 + Level;
        duration = 3 + (Level / 2);
    }
    else if (chosenType == "heal") {
        damage = 3 + Level;
        duration = 1;
    }
    else if (chosenType == "freeze") {
        duration = 2 + (Level / 3);
        chance = 40 + Level;
    }
    else if (chosenType == "cursed") {
        damage = 2 + Level;
        duration = 3;
    }
    else if (chosenType == "paralyzed") {
        duration = 2 + (Level / 2);
        chance = 30 + Level;
    }

    StatusEffect Effect(chosenType, damage, duration, chance);

    std::string name = chosenType + " potion";

    Item reward(name, Effect);

    return Cave(CaveMonsters, reward);
}

void Game::enterCave(){
    Cave Cave = generateCave();

    std::cout << "Monsters in cave: ";
    Cave.printMonsters();

    bool Completed = Cave.startCave(Player);

    if(Completed){
        std::cout << "Cave completed!\n";

        Player.resetHp();

        Item Reward = Cave.getReward();
        Player.giveItemToMonster(Reward);
    } else {
        std::cout << "You died\n";
        createCharacter();
    }

}
