#include "shade.h"
#include "enemy.h"

const int Shade::BASEHP = 125;
const int Shade::BASEATK = 25;
const int Shade::BASEDEF = 25;

Shade::Shade(Location location): Player(BASEHP, BASEATK, BASEDEF, location, 0, "Shade") {}

int Shade::getBaseHp(){
	return Shade::BASEHP;
}

int Shade::getBaseAtk() {
	return Shade::BASEATK;
}

int Shade::getBaseDef(){
	return Shade::BASEDEF;
}

void Shade::attack(Enemy * e){
	e->attackedBy(this);
}
