#ifndef _DROPSGOLD_H_
#define _DROPSGOLD_H_

#include "enemy.h"
#include <vector>
#include <string>

class Player;
class Goblin;

class DropsGold : public Enemy{
public:
	DropsGold(int health, int attack, int defence, Location location, char c);
	std::string killedBy(Player * p) override;
	std::string killedBy(Goblin * g) override;
    virtual void dropGold();
};

#endif
