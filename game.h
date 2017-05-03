#ifndef _GAME_
#define _GAME_


#include <string>
#include "floor.h"


class Game
{
	std::vector<Floor*> floors;
	int level;
	Player *player;
	bool enemy_movement;
    std::string action;

    int next_level();
	void read_floors(std::ifstream);
	Floor* parse_floor(std::vector<std::string>);

	friend std::ostream &operator<<(std::ostream &out, const Game &f);

public:
	Game(Player*, std::string);
	~Game();
    Game& operator=(Game &&other);

	int process_input(std::string);
};

#endif
