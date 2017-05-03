#include "dragon.h"
#include "constants.h"
#include "player.h"
#include "location.h"
#include "direction.h"
#include "floortile.h"

const int Dragon::BASEHP = 150;
const int Dragon::BASEATK = 20;
const int Dragon::BASEDEF = 20;

Dragon::Dragon(Location location, Floortile *dh) : DropsGold(BASEHP, BASEATK, BASEDEF, location, DRAGON_CHAR), hoard(dh) {}

int Dragon::getBaseHp(){
	return BASEHP;
}
int Dragon::getBaseAtk(){
	return BASEATK;
}
int Dragon::getBaseDef(){
	return BASEDEF;
}

bool Dragon::willMove() const {
    return false;
}

bool Dragon::willAttack(Player *p) const {
    Location hoard_loc = {hoard->getX(), hoard->getY()};
    return withinRange(p->getLocation(), getLocation()) || withinRange(p->getLocation(), hoard_loc);
}

void Dragon::attack(Player * p){
	p->attackedBy(this);
}

void Dragon::dropGold() {
    hoard->getGold()[0]->makeCollectible();
}
