/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <iostream>
#include "location.h"

class Direction;
class Floortile;

class Character{
	int hp;
	int atk;
	int def;
    const int base_hp;
    const int base_atk;
    const int base_def;
	Location loc;
    const char displayChar;
public:
	static int calculateDamage(int, int);

	Character(int hp, int atk, int def, Location loc, char c);
	virtual ~Character();

	virtual int getBaseHp();
	virtual int getBaseAtk();
	virtual int getBaseDef();

	bool isDead();

	virtual void attackedBy(Character * c);

    virtual void move(Direction dir, Floortile * cell);

	//accessors
	int getHp() const;
	int getAtk() const;
	int getDef() const;
	Location getLocation() const;

	//mutators
	void setHp(int health);
	void setAtk(int attack);
	void setDef(int defence);
	void setLocation(Location location);

	//modifiers
	virtual void modifyHp(int health);
	void modifyAtk(int attack);
	void modifyDef(int defence);

    std::string getStr() const;
    friend std::ostream &operator<<(std::ostream &out, const Character &c);
};


#endif
