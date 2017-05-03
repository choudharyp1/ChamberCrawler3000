/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "player.h"

class Vampire : public Player {
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Vampire(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;
	void modifyHp(int health) override;
	void attack(Enemy * e) override;
};


#endif
