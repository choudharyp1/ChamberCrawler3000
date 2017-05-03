#ifndef _ORC_H_
#define _ORC_H_

#include "givesgold.h"

class Player;

class Orc: public GivesGold{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Orc(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;

	void attack(Player * p) override;
};

#endif
