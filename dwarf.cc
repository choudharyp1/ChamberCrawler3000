#include "dwarf.h"
#include "constants.h"
#include "normal.h"
#include "player.h"
#include "vampire.h"

using namespace std;

const int Dwarf::BASEHP = 100;
const int Dwarf::BASEATK = 20;
const int Dwarf::BASEDEF = 30;

Dwarf::Dwarf(Location location) : GivesGold(BASEHP, BASEATK, BASEDEF, location, DWARF_CHAR) {
	Gold * g = new NormalPile();
	gld.push_back(g);
}

int Dwarf::getBaseHp(){
	return BASEHP;
}
int Dwarf::getBaseAtk(){
	return BASEATK;
}
int Dwarf::getBaseDef(){
	return BASEDEF;
}

void Dwarf::attack(Player * p){
	p->attackedBy(this);
}

void Dwarf::attackedBy(Vampire * v){
	int damage = Character::calculateDamage(v->getAtk(), getDef());
	modifyHp(-1 * damage);
	v->modifyHp(-1 * VAMPIRE_HP_BONUS);
}
