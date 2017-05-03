#include "dropsgold.h"
#include "constants.h"
#include "floortile.h"
#include "goblin.h"

class Gold;

DropsGold::DropsGold(int health, int attack, int defence, Location loc, char c): Enemy(health, attack, defence, loc, c) {}

std::string DropsGold::killedBy(Player * p){
    dropGold();
    return "";
}

std::string DropsGold::killedBy(Goblin * g){
    dropGold();
    g->addGold(GOBLIN_GOLD_BONUS);
    return "";
}

void DropsGold::dropGold(){
    getLocation().c->setUnoccupied();
	for (auto g: gld){
		getLocation().c->addGold(g);
	}
    gld.clear();
}
