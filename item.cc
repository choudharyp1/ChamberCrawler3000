/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "item.h"

Item::Item(bool c, int v, std::string s) : collectible(c), value(v), displayStr(s) {}

Item::~Item() {}

bool Item::isCollectible() const {
    return collectible;
}

void Item::makeCollectible() {
    collectible = true;
}

std::string Item::getStr() const {
    return displayStr;
}
