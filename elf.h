/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _ELF_H_
#define _ELF_H_

#include "givesgold.h"

class Player;

class Elf: public GivesGold{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Elf(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;

	void attack(Player * p) override;
};

#endif
