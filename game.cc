/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - game.cc
 */

#include "constants.h"
#include "direction.h"
#include "doorway.h"
#include "floor.h"
#include "floortile.h"
#include "game.h"
#include "passage.h"
#include "stairway.h"
#include "wall.h"
#include "player.h"
#include <fstream>
#include <iomanip>


Game::Game(Player *pc, std::string file) : level{0}, player{pc}, enemy_movement{true}, action{" Player character has spawned."}
{
	read_floors(std::ifstream{file});
	floors[level]->init(pc);
	std::cout << *this;
}

Game::~Game()
{
    floors[level]->removePlayer(player);
	for(int i = 0; i < NUM_LEVELS; i++)
    {
		delete floors[i];
    }
    delete player;
}

Game& Game::operator=(Game &&other) {
    std::swap(floors, other.floors);
    std::swap(level, other.level);
    std::swap(player, other.player);
    std::swap(enemy_movement, other.enemy_movement);
    action = "";
    return *this;
}


int Game::process_input(std::string input)
{
    action = "";
	if(input.substr(0, 2) == "u ")
        action += floors[level]->usePotion(player, input.substr(2));
	else if(input.substr(0, 2) == "a ")
	{
		Direction d = input.substr(2);
		action += floors[level]->attack(player, d);
	}
	else if(input == "f")
    {
		enemy_movement ^= true;
		return false;
    }
	else
    {
		action += floors[level]->player_move(player, input);
    }

    if(floors[level]->onStairs(player)) {
        // move to the next level or win the game
        if(next_level() == GAME_WON) {
            std::cout << "You won cc3k and escaped the dungeon with " << player->getGold() << " gold!" << std::endl;
            return GAME_WON;
        }
	} else {
        // enemies take their turn
		action += floors[level]->turn(player);
    }

	std::cout << *this;

    if (player->isDead()) {
        std::cout << "PC has died. Game over." << std::endl;
        return GAME_OVER;
    } else {
        return CONTINUE;
    }
}

int Game::next_level()
{
    floors[level]->removePlayer(player);
    if (level + 1 >= NUM_LEVELS) {
        return GAME_WON;
    } else {
        level++;
        floors[level]->init(player);
        return 0;
    }
}

void Game::read_floors(std::ifstream f)
{
	for(int i = 0; i < NUM_LEVELS; i++)
	{
		std::vector<std::string> r(FLOOR_HEIGHT);
		for(int i = 0; i < FLOOR_HEIGHT; i++)
			getline(f, r[i]);

		floors.push_back(parse_floor(r));
	}
}

Floor* Game::parse_floor(std::vector<std::string> r)
{
	std::vector<std::vector<Cell*>> grid;
	for(int i = 0; i < FLOOR_HEIGHT; i++)
	{
		std::vector<Cell*> row;
		for(int j = 0; j < FLOOR_WIDTH; j++)
			row.push_back(Cell::create(r[i][j], i, j));

		grid.push_back(row);
	}

	return new Floor(grid);
}

std::ostream &operator<<(std::ostream &out, const Game &g)
{
	for(int i = 0; i < 100; i++)
		out << std::endl;
	out << *g.floors[g.level];
    out.width(FLOOR_WIDTH-10);
    std::string s = "Race: " + g.player->getRace() + " Gold: " + std::to_string(g.player->getGold());
    out << std::left << s;
    out << "Floor: " << g.level+1 << std::endl;
    out << "HP: " << g.player->getHp() << std::endl;
    out << "Atk: " << g.player->getAtk() << std::endl;
    out << "Def: " << g.player->getDef() << std::endl;
    out << "Action:" << g.action << std::endl;
    return out;
}
