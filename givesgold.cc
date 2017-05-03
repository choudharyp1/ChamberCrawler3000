#include "givesgold.h"
#include "constants.h"
#include "floortile.h"
#include "goblin.h"

GivesGold::GivesGold(int health, int attack, int defence, Location loc, char c): Enemy(health, attack, defence, loc, c) {}

std::string GivesGold::killedBy(Player * p){
    return giveGold(p);
}

std::string GivesGold::killedBy(Goblin * g){
    g->addGold(GOBLIN_GOLD_BONUS);
    return giveGold(g);
}

std::string GivesGold::giveGold(Player * p){
    std::string s;
    getLocation().c->setUnoccupied();
    s += p->collect(gld);
    for (auto g : gld ) {
        delete g;
    }
    gld.clear();
    return s;
}
