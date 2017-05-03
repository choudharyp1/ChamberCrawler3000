/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "drow.h"
#include "elf.h"
#include "potion.h"

const int Drow::BASEHP = 150;
const int Drow::BASEATK = 25;
const int Drow::BASEDEF = 15;

Drow::Drow(Location location): Player(BASEHP, BASEATK, BASEDEF, location, 0, "Drow") {}

int Drow::getBaseHp(){
	return Drow::BASEHP;
}

int Drow::getBaseAtk(){
	return Drow::BASEATK;
}

int Drow::getBaseDef(){
	return Drow::BASEDEF;
}

void Drow::attack(Enemy * e){
	e->attackedBy(this);
}

void Drow::attackedBy(Elf * e){
    if (std::rand() % 2) {
	    int damage = Character::calculateDamage(e->getAtk(), getDef());
	    modifyHp(damage * -1);
    }
}

std::string Drow::drink(Potion *p){
    p->affect(this);
    std::string s = " PC used " + p->getStr();
    return s;
}
