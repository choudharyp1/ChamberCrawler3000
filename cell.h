/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _CELL_
#define _CELL_
#include <iostream>
#include <vector>

class Player;
class Enemy;
class Gold;
class Potion;


// an abstract class representing a cell
class Cell {
    const int x;
    const int y;
    char displayChar;
protected:
    Potion *ptn;
    std::vector<Gold *> gld;
public:
    Cell(int, int, char);
    virtual ~Cell();

    int getX() const;
    int getY() const;

    // methods for Floortile
    virtual bool isOccupied() const;        // indicates whether the cell is occupied or not
    virtual void setOccupied();             // informs the cell that it is occupied
    virtual void setUnoccupied();           // informs the cell that is is unoccupied
    virtual bool hasGold() const;           // indicates whether the cell has Gold or not
    virtual bool hasPotion() const;         // indicates whether the cell has Potions or not
    virtual void addGold(Gold *);           // adds a Gold object to the cell
    virtual void addPotion(Potion *);       // adds a Potion object to the cell
    std::vector<Gold *> &getGold();         // returns all Gold on the cell
    Potion *getPotion();                    // returns the Potion on the cell
    virtual void clearItems();              // clears all items in the cell

    // more virtual methods
    virtual bool isStairs() const;          // indicates whether the cell is a stairway or not
    virtual bool canHost(Player *) const;   // indicates whether the cell can host a Player or not
    virtual bool canHost(Enemy *) const;    // indicates whether the cell can host an Enemy or not

    static Cell* create(char, int, int);    // creates the specified Cell object with the given coordinates

    void setChar(char);
    friend std::ostream &operator<<(std::ostream &out, const Cell &c);
};

#endif
