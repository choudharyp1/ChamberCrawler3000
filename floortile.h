/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _FLOORTILE_
#define _FLOORTILE_
#include <iostream>
#include <vector>
#include "cell.h"

class Potion;
class Gold;

class Floortile : public Cell {
    bool occupied;
public:
    Floortile(int x, int y);

    bool isOccupied() const override;   // indicates whether the cell is occupied or not
    void setOccupied() override;        // informs the cell that it is occupied
    void setUnoccupied() override;      // informs the cell that is is unoccupied

    bool hasGold() const override;
    bool hasPotion() const override;
    void addGold(Gold *) override;               // adds a Gold object to the cell
    void addPotion(Potion *) override;           // adds a Potion object to the cell

    void clearItems() override;                  // clears the cell of all items

    bool canHost(Player *) const override;
    bool canHost(Enemy *) const override;
};

#endif
