/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _HP_MOD_
#define _HP_MOD_
#include <string>
#include "potion.h"

class HpMod : public Potion {
public:
    HpMod(int v, std::string d);
    void affect(Player *p) override;    // modifies the Player's health points
    void affect(Drow * d) override;
};

#endif
