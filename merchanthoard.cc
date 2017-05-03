/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "merchanthoard.h"
#include "constants.h"

const int MerchantHoard::VALUE = 4;
const bool MerchantHoard::COLLECTIBLE = true;
const std::string MerchantHoard::DISPLAYSTR = MH;

MerchantHoard::MerchantHoard() : Gold(COLLECTIBLE, VALUE, DISPLAYSTR) {}
