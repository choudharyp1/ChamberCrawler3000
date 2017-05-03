#ifndef _SHADE_H_
#define _SHADE_H_

#include "player.h"

class Shade : public Player{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Shade(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;

	void attack(Enemy * e) override;
};


#endif
