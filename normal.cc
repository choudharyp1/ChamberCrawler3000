/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "normal.h"
#include "constants.h"

const int NormalPile::VALUE = 2;
const bool NormalPile::COLLECTIBLE = true;
const std::string NormalPile::DISPLAYSTR = NP;

NormalPile::NormalPile() : Gold(COLLECTIBLE, VALUE, DISPLAYSTR) {}
