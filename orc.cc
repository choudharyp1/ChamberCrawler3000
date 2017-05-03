/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "orc.h"
#include "constants.h"
#include "player.h"
#include "normal.h"

class Gold;

const int Orc::BASEHP = 180;
const int Orc::BASEATK = 30;
const int Orc::BASEDEF = 25;

Orc::Orc(Location location) : GivesGold(BASEHP, BASEATK, BASEDEF, location, ORC_CHAR) {
	Gold * g = new NormalPile();
	gld.push_back(g);
}

int Orc::getBaseHp(){
	return BASEHP;
}
int Orc::getBaseAtk(){
	return BASEATK;
}
int Orc::getBaseDef(){
	return BASEDEF;
}

void Orc::attack(Player * p){
	p->attackedBy(this);
}
