#include "vampire.h"
#include "enemy.h"
#include "potion.h"

const int Vampire::BASEHP = 50;
const int Vampire::BASEATK = 25;
const int Vampire::BASEDEF = 25;

Vampire::Vampire(Location location): Player(BASEHP, BASEATK, BASEDEF, location, 0, "Vampire") {}

int Vampire::getBaseHp(){
	return BASEHP;
}

int Vampire::getBaseAtk(){
	return BASEATK;
}

int Vampire::getBaseDef(){
	return BASEDEF;
}

void Vampire::modifyHp(int health){
	int hp = getHp();
	if (health >= 0){
		setHp(hp + health);
	}else if ((-1 * health) >= hp){
		setHp(0);
	}else{
		setHp(hp + health);
	}
}

void Vampire::attack(Enemy * e){
	e->attackedBy(this);
}

