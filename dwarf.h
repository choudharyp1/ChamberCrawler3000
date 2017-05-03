#ifndef _DWARF_H_
#define _DWARF_H_

#include "givesgold.h"
#include "gold.h"
#include "normal.h"

class Vampire;

class Dwarf : public GivesGold{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Dwarf(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;
	void attackedBy(Vampire * v) override;

	void attack(Player * p) override;
};

#endif
