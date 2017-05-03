/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include <cmath>
#include "character.h"
#include "constants.h"
#include "direction.h"
#include "floortile.h"

Character::Character(int hp, int atk, int def, Location loc, char c): hp{hp}, atk{atk}, def{def}, base_hp{hp}, base_atk{atk}, base_def{def}, loc{loc}, displayChar{c} {}

Character::~Character(){}

int Character::calculateDamage(int attack, int defence){
	return ceil((100.0/(100.0 + defence)) * attack);
}

//accessors
int Character::getHp() const{
	return hp;
}
int Character::getAtk() const{
	return atk;
}
int Character::getDef() const{
	return def;
}
int Character::getBaseHp() {
    return base_hp;
}
int Character::getBaseAtk() {
    return base_atk;
}
int Character::getBaseDef() {
    return base_def;
}
Location Character::getLocation() const{
	return loc;
}

//mutators
void Character::setHp(int health){
	if (health > 0){
		hp = health;
	}else{
		hp = 0;
	}
}
void Character::setAtk(int attack){
	if (attack > 0){
		atk = attack;
	}else{
		atk = 0;
	}
}

void Character::setDef(int defence){
	if (defence > 0){
		def = defence;
	}else{
		def = 0;
	}
}

void Character::move(Direction dir, Floortile * cell) {
	Location loc = getLocation();
	loc.x += dir.x;
	loc.y += dir.y;
	loc.c->setUnoccupied();
	loc.c = cell;
	loc.c->setOccupied();
	setLocation(loc);
}

//modifiers
void Character::modifyHp(int health){
	if (health >= 0){
		hp += health;
	}else if ((-1 * health) >= hp){
		hp = 0;
	}else{
		hp += health;
	}

	if(hp > getBaseHp()){
		hp = getBaseHp();
	}
}
void Character::modifyAtk(int attack){
	if (attack >= 0){
		atk += attack;
	}else if ((-1 * attack) >= atk){
		atk = 0;
	}else{
		atk += attack;
	}
}

void Character::modifyDef(int defense){
	if (defense >= 0){
		def += defense;
	}else if ((-1 * defense) >= def){
		def = 0;
	}else{
		def += defense;
	}
}


void Character::setLocation(Location location){
	loc.x = location.x;
	loc.y = location.y;
	loc.c = location.c;
}

bool Character::isDead(){
	return hp <= 0;
}

void Character::attackedBy(Character * c){
	int damage = calculateDamage(c->getAtk(), getDef());
	modifyHp((-1 * damage));
}

std::string Character::getStr() const {
    return std::string(1, displayChar);
}

std::ostream &operator<<(std::ostream &out, const Character &c) {
    return out << c.displayChar;
}
