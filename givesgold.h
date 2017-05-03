#ifndef _GIVESGOLD_H_
#define _GIVESGOLD_H_

#include "enemy.h"
#include <vector>
#include <string>


class Player;
class Goblin;

class GivesGold : public Enemy{
public:
	GivesGold(int health, int attack, int defence, Location location, char c);
	std::string killedBy(Player * p) override;
	std::string killedBy(Goblin * g) override;
private:
    std::string giveGold(Player * p);
};

#endif
