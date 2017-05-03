/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _SMALL_
#define _SMALL_
#include <string>
#include "gold.h"

class SmallPile : public Gold {
    static const int VALUE;
    static const bool COLLECTIBLE;
    static const std::string DISPLAYSTR;
public:
    SmallPile();
};

#endif
