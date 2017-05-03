#include <stdlib.h>
#include <time.h>
#include "halfling.h"
#include "constants.h"
#include "character.h"
#include "player.h"
#include "gold.h"
#include "normal.h"
#include "vampire.h"

const int Halfling::BASEHP = 100;
const int Halfling::BASEATK = 15;
const int Halfling::BASEDEF = 20;

Halfling::Halfling(Location location) : GivesGold(BASEHP, BASEATK, BASEDEF, location, HALFLING_CHAR) {
	Gold * g = new NormalPile();
	gld.push_back(g);
}

int Halfling::getBaseHp(){
	return BASEHP;
}
int Halfling::getBaseAtk(){
	return BASEATK;
}
int Halfling::getBaseDef(){
	return BASEDEF;
}

void Halfling::attack(Player * p){
	p->attackedBy(this);
}

void Halfling::attackedBy(Character * c){
	srand(time(NULL));
	int x = rand();
	if (x % 2 == 0){
		int damage = Character::calculateDamage(c->getAtk(), getDef());
		modifyHp(-1 * damage);
	}
}

void Halfling::attackedBy(Vampire * v){
	srand(time(NULL));
	int x = rand();
	if (x % 2 == 0){
		int damage = Character::calculateDamage(v->getAtk(), getDef());
		modifyHp(-1 * damage);
		v->modifyHp(VAMPIRE_HP_BONUS);
	}
}
