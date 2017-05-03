/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "dragonhoard.h"
#include "constants.h"

const int DragonHoard::VALUE = 6;
const std::string DragonHoard::DISPLAYSTR = DH;

DragonHoard::DragonHoard() : Gold(false, VALUE, DISPLAYSTR) {}
