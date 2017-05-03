#include "merchant.h"
#include "constants.h"
#include "merchanthoard.h"
#include "character.h"
#include "player.h"
#include "vampire.h"

class Gold;

const int Merchant::BASEHP = 30;
const int Merchant::BASEATK = 70;
const int Merchant::BASEDEF = 5;
bool Merchant::isHostile = false;

Merchant::Merchant(Location location) : DropsGold(BASEHP, BASEATK, BASEDEF, location, MERCHANT_CHAR) {
	Gold * g = new MerchantHoard();
	gld.push_back(g);
}

int Merchant::getBaseHp(){
	return BASEHP;
}
int Merchant::getBaseAtk(){
	return BASEATK;
}
int Merchant::getBaseDef(){
	return BASEDEF;
}

bool Merchant::willAttack(Player *p) const {
    return isHostile && withinRange(p->getLocation(), this->getLocation());
}

void Merchant::attack(Player * p){
	p->attackedBy(this);
}

void Merchant::attackedBy(Character * c){
	isHostile = true;
	int damage = Character::calculateDamage(c->getAtk(), getDef());
	modifyHp((-1 * damage));
}

void Merchant::attackedBy(Vampire * v){
	isHostile = true;
	int damage = Character::calculateDamage(v->getAtk(), getDef());
	modifyHp((-1 * damage));
	v->modifyHp(VAMPIRE_HP_BONUS);
}

void Merchant::toggleHostile(){
	isHostile = !isHostile;
}

bool Merchant::getHostile(){
	return isHostile;
}
