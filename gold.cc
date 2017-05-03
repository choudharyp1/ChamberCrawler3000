/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include <string>
#include <random>
#include "gold.h"
#include "player.h"
#include "drow.h"
#include "vampire.h"

#include "small.h"
#include "normal.h"
#include "dragonhoard.h"

Gold::Gold(bool c, int v, std::string d) : Item(c, v, d), displayStr(d) {}

Gold * Gold::create() {
    // generate random number between 0-7
	int r = std::rand() % 8;
    if (r < 2) {                // 1/4 probability of SmallPile
        return new SmallPile;
    } else if (r == 2) {        // 1/8 probability of DragonHoard
        return nullptr;         // will be created by floor class
    } else {                    // 5/8 probability of NormalPile
        return new NormalPile;
    }
}

void Gold::affect(Player * p) {
    p->addGold(value);
}

void Gold::affect(Drow * d) {
    d->addGold(value);
}

std::ostream &operator<<(std::ostream &out, const Gold &g) {
    return out << " collects " << g.displayStr;
}
