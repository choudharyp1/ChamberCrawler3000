/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "floortile.h"
#include "constants.h"
#include "item.h"
#include "gold.h"

Floortile::Floortile(int x, int y) : Cell(x, y, FLOOR_CHAR), occupied(false) {}

// occupied methods
bool Floortile::isOccupied() const {
    return (occupied || hasPotion() || hasGold());
}

void Floortile::setOccupied() {
    occupied = true;
}

void Floortile::setUnoccupied() {
    occupied = false;
}

// item methods
bool Floortile::hasGold() const {
    return (gld.size() > 0);
}

bool Floortile::hasPotion() const {
    return (ptn != nullptr);
}

void Floortile::addGold(Gold *g) {
    if (!hasPotion()) {
        gld.push_back(g);
    }
    setChar(GOLD_CHAR);
}

void Floortile::addPotion(Potion *p) {
    if (!hasGold() && !hasPotion()) {
        ptn = p;
    }
    setChar(POTION_CHAR);
}

void Floortile::clearItems() {
    gld.clear();
    ptn = nullptr;
    setChar(FLOOR_CHAR);
}

// "can host?" methods
bool Floortile::canHost(Player *) const {
    // player can occupy the cell if the cell is currently unoccupied,
    // it has no potion, and all gold in the cell are collectible
    bool collectible = true;
    for (auto g : gld) {
        collectible = collectible && g->isCollectible();
    }
    return (!occupied && !hasPotion() && collectible);
}

bool Floortile::canHost(Enemy *) const {
    // enemy can occupy a cell if the the cell is currently unoccupied and there are no items
    return !this->isOccupied();
}
