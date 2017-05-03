/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "emptytile.h"
#include "constants.h"

Emptytile::Emptytile(int x, int y) : Cell(x, y, EMPTY_CHAR) {};

bool Emptytile::canHost(Player *) const {
    return false;
}
