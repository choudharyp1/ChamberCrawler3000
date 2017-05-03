#include "elf.h"
#include "constants.h"
#include "player.h"
#include "normal.h"

class Gold;

const int Elf::BASEHP = 140;
const int Elf::BASEATK = 30;
const int Elf::BASEDEF = 10;

Elf::Elf(Location location) : GivesGold(BASEHP, BASEATK, BASEDEF, location, ELF_CHAR) {
	Gold * g = new NormalPile();
	gld.push_back(g);
}

int Elf::getBaseHp(){
	return BASEHP;
}
int Elf::getBaseAtk(){
	return BASEATK;
}
int Elf::getBaseDef(){
	return BASEDEF;
}

void Elf::attack(Player * p){
	p->attackedBy(this);
}

