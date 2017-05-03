#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "givesgold.h"

class Player;
class Vampire;

class Halfling : public GivesGold{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Halfling(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;

	void attack(Player * p) override;
	void attackedBy(Character * c) override;
	void attackedBy(Vampire * v) override;
};

#endif
