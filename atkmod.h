/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _ATK_MOD_
#define _ATK_MOD_
#include <string>
#include "potion.h"

class AtkMod : public Potion {
public:
    AtkMod(int v, std::string d);
    void affect(Player *p) override;    // modifies the Player's attack stat
    void affect(Drow * d) override;

};

#endif
