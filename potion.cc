/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include <random>
#include <ctime>
#include "potion.h"
#include "constants.h"
#include "atkmod.h"
#include "defmod.h"
#include "hpmod.h"

Potion::Potion(int v, std::string d) : Item(false, v, d), displayStr(d) {}

Potion * Potion::create() {
    // generate random number between 0-5
	int r = std::rand() % 6;
    // probabilty 1/6 for each type of potion
    switch(r)
    {
        case 0:
            return new AtkMod(5, BA);  // Boost Attack
        case 1:
            return new AtkMod(-5, WA); // Wound Attack
        case 2:
            return new DefMod(5, BD);  // Boost Defense
        case 3:
            return new DefMod(-5, WD); // Wound Defense
        case 4:
            return new HpMod(10, RH);  // Restore Health
        case 5:
            return new HpMod(-10, PH); // Poison Health
        default:
            return nullptr;
    }
}

std::ostream &operator<<(std::ostream &out, const Potion &p) {
    return out /*<< " uses "*/ << p.displayStr;
}
