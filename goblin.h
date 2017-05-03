/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "player.h"

class Orc;

class Goblin : public Player{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Goblin(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;
	void killed(Enemy * e) override;
	void attackedBy(Orc * o) override;
	void attack(Enemy * e) override;
};

#endif
