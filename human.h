#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "dropsgold.h"

class Player;

class Human : public DropsGold{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Human(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;

	void attack(Player * p) override;
};

#endif
