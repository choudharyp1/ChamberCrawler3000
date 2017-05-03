/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "player.h"
#include <string>
#include <random>
#include "constants.h"
#include "gold.h"
#include "potion.h"

#include "drow.h"
#include "goblin.h"
#include "shade.h"
#include "troll.h"
#include "vampire.h"
#include "enemy.h"
#include "orc.h"
#include "elf.h"

Player::Player(int health, int attack, int defence, Location location, int gold, std::string race):
Character(health, attack, defence, location, PLAYER_CHAR), gold{gold}, race{race} {}

Player::~Player() {}

void Player::newFloorReset(){
    setAtk(getBaseAtk());
    setDef(getBaseDef());
}

std::string Player::drink(Potion *p) {
    p->affect(this);
    std::string s = " PC used " + p->getStr() + ".";
    return s;
}

std::string Player::collect(std::vector<Gold *> g) {
    std::string s;
    for (auto pile : g) {
        if (pile->isCollectible()) {
            pile->affect(this);
            s += " PC collects " + pile->getStr() + ".";
        }
    }
    return s;
}

void Player::addGold(int value) {
    gold += value;
}

int Player::getGold() const {
    return gold;
}

std::string Player::getRace() const {
    return race;
}

void Player::attackedBy(Enemy *e){
    if (std::rand() % 2) {
        int damage = Character::calculateDamage(e->getAtk(), getDef());
        modifyHp(damage * -1);
    }
}

void Player::attackedBy(Elf *e){
    if (std::rand() % 2) {
        int damage = Character::calculateDamage(e->getAtk(), getDef());
        modifyHp(damage * -2);
    }
}

void Player::attackedBy(Orc * o){
    if (std::rand() % 2) {
        int damage = Character::calculateDamage(o->getAtk(), getDef());
        modifyHp(damage * -1);
    }
}

void Player::killed(Enemy * e){
    e->killedBy(this);
}

Player * Player::create(char c, Location location){
    switch(c)
    {
        case 's':
            return new Shade(location);

        case 'd':
            return new Drow(location);

        case 'v':
            return new Vampire(location);

        case 'g':
            return new Goblin(location);

        case 't':
            return new Troll(location);

        default:
            return nullptr;
    }
}
