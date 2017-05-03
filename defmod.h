/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _DEF_MOD_
#define _DEF_MOD_
#include <string>
#include "potion.h"

class DefMod : public Potion {
public:
    DefMod(int v, std::string d);
    void affect(Player *p) override;    // modifies the Player's defense stat
    void affect(Drow * d) override;
};

#endif
