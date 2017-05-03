/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <sstream>
#include "floor.h"
#include "constants.h"
#include "cell.h"
#include "chamber.h"
#include "floortile.h"
#include "stairway.h"
#include "location.h"
#include "player.h"
#include "potion.h"
#include "gold.h"
#include "enemy.h"
#include "dragon.h"
#include "dragonhoard.h"

Floor::Floor(std::vector<std::vector<Cell*>> g) : board{g},
charGrid{std::vector<std::vector<Character*>>(FLOOR_HEIGHT, std::vector<Character*>(FLOOR_WIDTH))}
{
    findChambers();
}

Floor::~Floor() {
    for (auto row : charGrid) {
        for (auto c : row) {
            delete c;
        }
    }
    for (auto row : board) {
        for (auto c : row) {
            delete c;
        }
    }
    for (auto i : items) {
        delete i;
    }
    for(auto c : chambers) {
        delete c;
    }
}

Floor& Floor::operator=(Floor &&other) {
    std::swap(board, other.board);
    std::swap(charGrid, other.charGrid);
    std::swap(chambers, other.chambers);
    std::swap(items,other.items);
    return *this;
}

std::vector<Floortile*> Floor::floodFill(int x, int y, bool vis[FLOOR_HEIGHT][FLOOR_WIDTH])
{
    std::vector<Floortile*> ans;
    ans.push_back(static_cast<Floortile*>(board[x][y]));

    vis[x][y] = true;
    for(int i = x - 1; i <= x + 1; i++)
        for(int j = y - 1; j <= y + 1; j++)
            if(0 <= i && i < FLOOR_HEIGHT && 0 <= j && j < FLOOR_WIDTH)
                if(dynamic_cast<Floortile*>(board[i][j]) && !vis[i][j])
                    for(auto ft : floodFill(i, j, vis))
                        ans.push_back(ft);

    return ans;
}

void Floor::findChambers()
{
    bool vis[FLOOR_HEIGHT][FLOOR_WIDTH] = {};
    for(int i = 0; i < FLOOR_HEIGHT; i++)
        for(int j = 0; j < FLOOR_WIDTH; j++)
            if(dynamic_cast<Floortile*>(board[i][j]) && !vis[i][j])
                chambers.push_back(new Chamber(floodFill(i, j, vis)));
}

void Floor::init(Player * p) {
    // first, spawn Player and Stairway
    // randomly choose two unique chambers
    std::vector<unsigned int> indices(chambers.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::random_shuffle(indices.begin(), indices.end());
    spawnPC(p, chambers[indices[0]]);
    spawnStairs(chambers[indices[1]]);

    // spawn potions
    spawnPotions();

    // spawn gold
    spawnGold();

    // spawn enemies
    spawnEnemies();
}

Floortile * Floor::randomTile() {
    int c = randomChamber();
    try {
        return chambers[c]->randomCell();
    } catch(int e) {
        return randomTile();
    }
}

int Floor::randomChamber() {
    return std::rand() % chambers.size();
}

void Floor::spawnPC(Player * pc, Chamber * ch) {
    pc->newFloorReset();
    Floortile *ft = ch->randomCell();
    Location loc{ft->getX(), ft->getY(), ft};
    pc->setLocation(loc);
    charGrid[loc.x][loc.y] = pc;
}

void Floor::spawnStairs(Chamber *ch) {
    Floortile *ft = ch->randomCell();
    int x = ft->getX();
    int y = ft->getY();
    delete board[x][y];
    board[x][y] = new Stairway(x, y);
}

void Floor::spawnPotions() {
    for (int i = 0; i < NUM_POTIONS; ++i) {
        Floortile * ft = randomTile();
        Potion * ptn = Potion::create();
        ft->addPotion(ptn);
        items.push_back(ptn);
    }
}

void Floor::spawnGold() {
    for (int i = 0; i < NUM_GOLD; ++i) {
        Floortile * ft = randomTile();
        Gold * gld = Gold::create();
        if (gld == nullptr) {       // spawn dragonhoard and dragon
            Location loc = randomNeighbour(ft);
            loc.c->setOccupied();
            DragonHoard * hoard = new DragonHoard;
            items.push_back(hoard);
            ft->addGold(hoard);
            Dragon * dgn = new Dragon(loc, ft);
            charGrid[loc.x][loc.y] = dgn;
        } else {
            items.push_back(gld);
            ft->addGold(gld);
        }
    }
}

Location Floor::randomNeighbour(Floortile * ft) {
    std::vector<Location> opts;
    for (int i = ft->getX()-1; i < ft->getX()+1; i++) {
        for (int j = ft->getY()-1; j < ft->getY()+1; j++) {
            if (!(i == ft->getX() && j == ft->getY()) && !board[i][j]->isOccupied()) {
                opts.push_back(Location{i, j, static_cast<Floortile*>(board[i][j])});
            }
        }
    }
    if(!opts.size())
        throw 0;
    return opts[std::rand() % opts.size()];
}


void Floor::spawnEnemies() {
    for (int i = 0; i < NUM_ENEMIES; ++i) {
        Floortile * ft = randomTile();
        Location loc{ft->getX(), ft->getY(), ft};
        Enemy * nme = Enemy::create(loc);
        charGrid[loc.x][loc.y] = nme;
        ft->setOccupied();
    }
}

Cell* Floor::cell_at(int x, int y)
{
    return board[x][y];
}

bool Floor::onStairs(Player * pc)
{
    int x = pc->getLocation().x, y = pc->getLocation().y;
    return board[x][y]->isStairs();
}

void Floor::removePlayer(Player * pc) {
    int x = pc->getLocation().x, y = pc->getLocation().y;
    charGrid[x][y] = nullptr;
}

// gameplay

std::string Floor::turn(Player * pc)
{
    std::string s;
    if(pc->getRace() == "troll")
        pc->modifyHp(5);

    std::vector<Location> to_move;
    for(int i = 0; i < FLOOR_HEIGHT; i++) {
        for(int j = 0; j < FLOOR_WIDTH; j++) {
            if(dynamic_cast<Enemy*>(charGrid[i][j])) {
                if(static_cast<Enemy*>(charGrid[i][j])->willAttack(pc)) {
                    std::ostringstream ss{};
                    int beforeHealth = pc->getHp();
                    static_cast<Enemy*>(charGrid[i][j])->attack(pc);
                    int final = beforeHealth - pc->getHp();
                    s += " " + charGrid[i][j]->getStr() + " deals " + std::to_string(final) + " damage to PC.";
                } else if(static_cast<Enemy*>(charGrid[i][j])->willMove()){
                    to_move.push_back({i, j});
                }
            }
        }
    }
    for (unsigned int i = 0; i < to_move.size(); i++) {
        enemy_move(static_cast<Enemy*>(charGrid[to_move[i].x][to_move[i].y]));
    }
    return s;
}

std::string Floor::player_move(Player * pc, Direction dir)
{
    std::string s;
    int nx = pc->getLocation().x + dir.x, ny = pc->getLocation().y + dir.y;
    if(0 <= nx && nx < FLOOR_HEIGHT)
    {
        if(0 <= ny && ny < FLOOR_WIDTH)
        {
            if(cell_at(nx, ny)->canHost(pc))
            {
                pc->move(dir, static_cast<Floortile*>(cell_at(nx, ny)));
                s = pc->collect(cell_at(nx, ny)->getGold());
                cell_at(nx, ny)->clearItems();
                std::swap(charGrid[nx][ny], charGrid[nx - dir.x][ny - dir.y]);
            }
        }
    }
    return s;
}

std::string Floor::enemy_move(Enemy * e)
{
    int x = e->getLocation().x, y = e->getLocation().y;

    std::vector<Direction> opts;
    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            if((i | j) && (board[x + i][y + j]->canHost(e)))
                opts.push_back({i, j});

    if(!opts.size())
        return "";

    Direction d = opts[std::rand() % opts.size()];

    e->move(d, static_cast<Floortile*>(board[x + d.x][y + d.y]));
    std::swap(charGrid[x][y], charGrid[x + d.x][y + d.y]);

    return "";
}

std::string Floor::attack(Player * pc, Direction dir){
    std::string s;
    int nx = pc->getLocation().x + dir.x, ny = pc->getLocation().y + dir.y;
    if (0 <= nx && nx < FLOOR_HEIGHT){
        if (0 <= ny && ny < FLOOR_WIDTH){
            if (charGrid[nx][ny] != nullptr){
                int initialHealth = charGrid[nx][ny]->getHp();
                pc->attack(static_cast<Enemy *>(charGrid[nx][ny]));
                int afterHealth = charGrid[nx][ny]->getHp();
                int changeHealth = initialHealth - afterHealth;
                s = " PC deals " + std::to_string(changeHealth) + " to ";
                s += charGrid[nx][ny]->getStr() + " (";
                s += std::to_string(charGrid[nx][ny]->getHp()) + ").";
                s += isEnemyDead(pc, nx, ny);
            }else{
                s = " PC attacked an empty cell.";
            }
        }
    }
    return s;
}

std::string Floor::isEnemyDead(Player * pc, int x, int y) {
    std::string s;
    if (charGrid[x][y]->isDead()) {
        s = " PC killed enemy.";
        s += static_cast<Enemy *>(charGrid[x][y])->killedBy(pc);
        // add any dropped Gold to items to ensure proper deletion
        for (auto gld : board[x][y]->getGold()) {
            items.push_back(gld);
        }
        delete charGrid[x][y];
        charGrid[x][y] = nullptr;
    }
    return s;
}

std::string Floor::usePotion(Player * pc, Direction dir) {
    std::string s;
    int nx = pc->getLocation().x + dir.x, ny = pc->getLocation().y + dir.y;
    if (cell_at(nx, ny)->hasPotion()) {
        Potion * ptn = cell_at(nx, ny)->getPotion();
        s = pc->drink(ptn);
        cell_at(nx, ny)->clearItems();
    }
    return s;
}

std::ostream &operator<<(std::ostream &out, const Floor &f)
{
	for(int i = 0; i < FLOOR_HEIGHT; i++)
	{
		for(int j = 0; j < FLOOR_WIDTH; j++) {
            if(f.charGrid[i][j])
				out << *f.charGrid[i][j];
			else
				out << *f.board[i][j];
        }
		out << std::endl;
	}

	return out;
}
