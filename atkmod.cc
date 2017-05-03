/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "atkmod.h"
#include "constants.h"
#include "player.h"
#include "drow.h"
#include "vampire.h"
#include <cmath>

AtkMod::AtkMod(int v, std::string d) : Potion(v, d) {}

void AtkMod::affect(Player *p) {
    p->modifyAtk(value);
}

void AtkMod::affect(Drow * d){
	d->modifyAtk(ceil(value * DROW_EFFECT_X));
}

