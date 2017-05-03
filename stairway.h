/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _STAIRWAY_
#define _STAIRWAY_
#include <iostream>
#include "cell.h"
#include "doorway.h"

class Stairway : public Cell {
public:
    Stairway(int, int);
    bool isStairs() const override;
};

#endif
