/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "enemy.h"
#include <random>

#include "player.h"
#include "human.h"
#include "dwarf.h"
#include "halfling.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "vampire.h"

using namespace std;

Enemy::Enemy(int health, int attack, int defence, Location location, char c): Character(health, attack, defence, location, c) {}

Enemy::~Enemy()
{
    for(auto g : gld)
        delete g;
}

Enemy * Enemy::create(Location loc) {
    // generate random number between 0-17
    int r = std::rand() % 18;
    if (r < 4) {
        return new Human(loc);
    } else if (r < 7) {
        return new Dwarf(loc);
    } else if (r < 12){
        return new Halfling(loc);
    }else if (r < 14){
        return new Elf(loc);
    }else if (r < 16){
        return new Orc(loc);
    }else{
        return new Merchant(loc);
    }
}

bool Enemy::willMove() const {
    return true;
}

bool Enemy::willAttack(Player * p) const {
    return withinRange(p->getLocation(), getLocation());
}

void Enemy::attackedBy(Vampire * v){
    int damage = calculateDamage(v->getAtk(), getDef());
    modifyHp((-1 * damage));
    v->modifyHp(VAMPIRE_HP_BONUS);
}

void Enemy::toggleHostile(){ //doesn't need to do anything. However, an implementation was necessary.
}

bool Enemy::getHostile(){
    return true;
}

bool Enemy::withinRange(Location l1, Location l2) const {
    return (abs(l1.x - l2.x) <= 1 && abs(l1.y - l2.y) <= 1);
}
