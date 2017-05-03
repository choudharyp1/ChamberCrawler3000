#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "dropsgold.h"

class Character;
class Player;
class Vampire;

class Merchant : public DropsGold{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
	static bool isHostile;
public:
	Merchant(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;

    bool willAttack(Player *p) const override;
	void attack(Player * p) override;
	void attackedBy(Character * c) override;
	void attackedBy(Vampire * v) override;

	void toggleHostile() override;
	bool getHostile() override;

};

#endif
