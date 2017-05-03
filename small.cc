/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "small.h"
#include "constants.h"

const int SmallPile::VALUE = 1;
const bool SmallPile::COLLECTIBLE = true;
const std::string SmallPile::DISPLAYSTR = SP;

SmallPile::SmallPile() : Gold(COLLECTIBLE, VALUE, DISPLAYSTR) {}
