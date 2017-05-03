/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "stairway.h"
#include "constants.h"

Stairway::Stairway(int x, int y) : Cell(x, y, STAIR_CHAR) {};

bool Stairway::isStairs() const {
    return true;
}
