/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "hpmod.h"
#include "constants.h"
#include "player.h"
#include "drow.h"
#include "vampire.h"
#include <cmath>

HpMod::HpMod(int v, std::string d) : Potion(v, d) {}

void HpMod::affect(Player *p) {
    p->modifyHp(value);
}

void HpMod::affect(Drow *d) {
    d->modifyHp(ceil(value * DROW_EFFECT_X));
}
