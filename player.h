/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>
#include <vector>
#include "character.h"

class Potion;
class Gold;
class Enemy;
class Elf;
class Orc;

class Player : public Character {
    int gold;
    std::string race;
public:
    static Player * create(char c, Location loc);

    Player(int health, int attack, int defence, Location location, int gold, std::string race);
    ~Player();

    void newFloorReset();

    virtual std::string drink(Potion *p);
    std::string collect(std::vector<Gold *> g);

    using Character::attackedBy;
    virtual void attackedBy(Enemy *e);
    virtual void attackedBy(Elf *e);
    virtual void attackedBy(Orc * o);

    virtual void killed(Enemy * e);

    virtual void attack(Enemy * e) = 0;

    void addGold(int value);
    int getGold() const;
    std::string getRace() const;

};

#endif
