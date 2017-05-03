#ifndef _DROW_H_
#define _DROW_H_

#include "player.h"

class Drow : public Player{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Drow(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;
	std::string drink(Potion *p) override;

	void attack(Enemy * e) override;

	void attackedBy(Elf * e) override;
};

#endif
