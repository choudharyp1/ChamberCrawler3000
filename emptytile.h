/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _EMPTYTILE_
#define _EMPTYTILE_
#include <iostream>
#include "cell.h"
#include "constants.h"

class Player;

class Emptytile : public Cell {
public:
    Emptytile(int, int);
    bool canHost(Player *) const override;
};

#endif
