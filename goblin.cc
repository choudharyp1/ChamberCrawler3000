/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include <cmath>
#include <random>
#include "goblin.h"
#include "orc.h"

const int Goblin::BASEHP = 110;
const int Goblin::BASEATK = 15;
const int Goblin::BASEDEF = 20;

Goblin::Goblin(Location location): Player(BASEHP, BASEATK, BASEDEF, location, 0, "Goblin") {}

int Goblin::getBaseHp(){
	return Goblin::BASEHP;
}

int Goblin::getBaseAtk(){
	return Goblin::BASEATK;
}

int Goblin::getBaseDef(){
	return Goblin::BASEDEF;
}

void Goblin::killed(Enemy * e){
	e->killedBy(this);
}

void Goblin::attack(Enemy * e){
	e->attackedBy(this);
}

void Goblin::attackedBy(Orc * o){
    if (std::rand() % 2) {
	    int damage = Character::calculateDamage(o->getAtk(), getDef());
	    modifyHp(damage * -2);
    }
}
