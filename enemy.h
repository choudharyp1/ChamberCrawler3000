/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _ENEMY_H_
#define _ENEMY_H_

#include <vector>
#include <string>
#include "gold.h"
#include "character.h"
#include "location.h"

class Player;
class Floor;
class Goblin;
class Vampire;

class Enemy : public Character{
protected:
    std::vector<Gold *> gld;
public:
    Enemy(int health, int attack, int defence, Location location, char c);
    ~Enemy();

    static Enemy * create(Location loc);

    virtual bool willMove() const;
    virtual bool willAttack(Player * p) const;
    virtual void attack(Player * p) = 0;
    using Character::attackedBy;
    virtual void attackedBy(Vampire * v);
    virtual std::string killedBy(Player * p) = 0;
    virtual std::string killedBy(Goblin * g) = 0;

    virtual void toggleHostile();
    virtual bool getHostile();

protected:
    bool withinRange(Location, Location) const;
};


#endif
