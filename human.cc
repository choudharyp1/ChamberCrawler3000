#include "human.h"
#include "constants.h"
#include "normal.h"
#include "player.h"

class Gold;

const int Human::BASEHP = 140;
const int Human::BASEATK = 20;
const int Human::BASEDEF = 20;

Human::Human(Location location) : DropsGold(BASEHP, BASEATK, BASEDEF, location, HUMAN_CHAR) {
	Gold * g1 = new NormalPile();
	Gold * g2 = new NormalPile();
	gld.push_back(g1);
	gld.push_back(g2);
}

int Human::getBaseHp(){
	return BASEHP;
}
int Human::getBaseAtk(){
	return BASEATK;
}
int Human::getBaseDef(){
	return BASEDEF;
}

void Human::attack(Player * p){
	p->attackedBy(this);
}
