#ifndef _TROLL_H_
#define _TROLL_H_

#include "player.h"

class Troll : public Player {
	static const int BASEHP;
	static const int MAXHP;
	static const int BASEATK;
	static const int BASEDEF;
public:
	Troll(Location location);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;
	void modifyHp(int health) override;

	void attack(Enemy * e) override;
};


#endif
