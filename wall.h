/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _WALL_
#define _WALL_
#include "cell.h"

class Player;

class Wall : public Cell {
public:
    using Cell::Cell;
    bool canHost(Player *) const override;
};

#endif
