/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include <random>
#include <algorithm>
#include "chamber.h"
#include "floortile.h"

Chamber::Chamber() {}

Chamber::Chamber(std::vector<Floortile *> floortiles) : floortiles(floortiles) {}

Chamber::~Chamber() {
    floortiles.clear();
}

void Chamber::addTile(Floortile *ft) {
    floortiles.push_back(ft);
}

Floortile *Chamber::randomCell() {
    // filter out the invalid floortiles, so temp only contains valid floortiles for spawning
    std::vector<Floortile *> temp;
    std::copy_if(floortiles.begin(), floortiles.end(), std::back_inserter(temp), [](Floortile *f){return !f->isOccupied();});

    // raise exception if there are no Floortiles left
    if (temp.size() == 0) {
        throw 0;
    }

    // choose random index and return the cell pointer
    int randomIndex = std::rand() % temp.size();

    std::vector<Floortile*> newlst;
    for(auto tile : floortiles)
        if(tile != temp[randomIndex])
            newlst.push_back(tile);
    floortiles = newlst;

    // return the randomly chosen Floortile
    return temp[randomIndex];
}
