/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - main.cc
 */

#include <iostream>
#include <random>
#include <ctime>
#include "constants.h"
#include "game.h"
#include "player.h"

Player* choose_race();


int main(void)
{
    std::srand(std::time(0));
	std::cout << "WELCOME TO CHAMBER CRAWLER 3000" << std::endl;

	Game game{choose_race(), "cc3kfloor.txt"};

	std::string s;
	while(getline(std::cin, s))
		if(s == "q")
			break;
		else if(s == "r")
			game = Game{choose_race(), "cc3kfloor.txt"};
		else if (game.process_input(s))
            break;
}


Player* choose_race()
{
	std::cout << "ENTER YOUR DESIRED RACE TO BEGIN" << std::endl;
	std::cout << "ONE OF (s)HADE, (d)ROW, (v)AMPIRE, (g)OBLIN, (t)ROLL, (q)UIT:" << std::endl;

	char race;
	if(!(std::cin >> race) || race == 'q')
		exit(0);
	std::cin.ignore();

	return Player::create(race, {1, 2});
}
