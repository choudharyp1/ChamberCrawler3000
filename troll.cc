#include "troll.h"
#include "enemy.h"

const int Troll::BASEHP = 50;
const int Troll::MAXHP = 120;
const int Troll::BASEATK = 25;
const int Troll::BASEDEF = 25;

Troll::Troll(Location location): Player(BASEHP, BASEATK, BASEDEF, location, 0, "Troll") {}

int Troll::getBaseHp(){
	return Troll::BASEHP;
}
int Troll::getBaseAtk(){
	return Troll::BASEATK;
}
int Troll::getBaseDef(){
	return Troll::BASEDEF;
}

void Troll::modifyHp(int health){
	int hp = getHp();
	if (health >= 0){
		setHp(hp + health);
	}else if ((-1 * health) >= hp){
		setHp(0);
	}else{
		setHp(hp + health);
	}

	setHp(std::min(getHp(), MAXHP));
}


void Troll::attack(Enemy * e){
	e->attackedBy(this);
}
