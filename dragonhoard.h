/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _DRAGON_HOARD_
#define _DRAGON_HOARD_
#include <string>
#include "gold.h"

class DragonHoard : public Gold {
    static const int VALUE;
    static const std::string DISPLAYSTR;
public:
    DragonHoard();
};

#endif
