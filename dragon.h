#ifndef _DRAGON_H_
#define _DRAGON_H_

#include "dropsgold.h"
#include "gold.h"

class Floortile;

class Dragon: public DropsGold{
	static const int BASEHP;
	static const int BASEATK;
	static const int BASEDEF;
    Floortile *hoard;
public:
	Dragon(Location, Floortile *);
	int getBaseHp() override;
	int getBaseAtk() override;
	int getBaseDef() override;

    bool willMove() const override;
    bool willAttack(Player *p) const override;
	void attack(Player * p) override;

    void dropGold() override;

};


#endif
