/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _FLOOR_
#define _FLOOR_

#include <vector>
#include <string>
#include "constants.h"
#include "direction.h"

struct Location;
class Character;
class Cell;
class Floortile;
class Chamber;
class Player;
class Enemy;
class Item;

class Floor {
    std::vector<std::vector<Cell *>> board;
    std::vector<std::vector<Character *>> charGrid;
    std::vector<Chamber *> chambers;
    std::vector<Item *> items;

    friend std::ostream &operator<<(std::ostream &out, const Floor &f);

public:
    Floor(std::vector<std::vector<Cell *>> board);
    ~Floor();
    Floor& operator=(Floor &&other);

    void init(Player *);    // spawns the Player on a random, valid cell on the floor
                            // and generates all other game objects
    std::string turn(Player *);
    std::string usePotion(Player *, Direction);
    std::string player_move(Player *, Direction);
    std::string enemy_move(Enemy *);
    std::string attack(Player *, Direction);
    std::string isEnemyDead(Player *, int, int);
    void removePlayer(Player *);
    Cell* cell_at(int, int);
    bool onStairs(Player *);
private:
    void findChambers();
    std::vector<Floortile*> floodFill(int x, int y, bool vis[FLOOR_HEIGHT][FLOOR_WIDTH]);
    void spawnPC(Player *, Chamber *);
    void spawnStairs(Chamber *);
    void spawnPotions();
    void spawnGold();
    void spawnEnemies();
    int randomChamber();
    Floortile * randomTile();
    Location randomNeighbour(Floortile *);
};


#endif
