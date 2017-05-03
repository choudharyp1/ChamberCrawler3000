/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#include "cell.h"
#include "constants.h"
#include "doorway.h"
#include "emptytile.h"
#include "floortile.h"
#include "passage.h"
#include "stairway.h"
#include "nswall.h"
#include "ewwall.h"

Cell::Cell(int x, int y, char c) : x(x), y(y), displayChar(c), ptn(nullptr) {}

Cell::~Cell() {}

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

// virtual methods for Floortile
bool Cell::isOccupied() const {
    return true;
}
void Cell::setOccupied() {}
void Cell::setUnoccupied() {}
bool Cell::hasGold() const {
    return false;
}
bool Cell::hasPotion() const {
    return false;
}
void Cell::addGold(Gold *) {}
void Cell::addPotion(Potion *) {}
std::vector<Gold *> &Cell::getGold() {
    return gld;
}
Potion *Cell::getPotion() {
    return ptn;
}
void Cell::clearItems() {}

// more virtual methods
bool Cell::isStairs() const {
    return false;
}

bool Cell::canHost(Player *) const {
    return true;
}

bool Cell::canHost(Enemy *) const {
    return false;
}

// Cell creation
Cell* Cell::create(char c, int x, int y)
{
    switch(c)
	{
		case PASSAGE_CHAR:
			return new Passage(x, y);

		case DOORWAY_CHAR:
			return new Doorway(x, y);

		case NSWALL_CHAR:
            return new nsWall(x, y);

		case EWWALL_CHAR:
			return new ewWall(x, y);

		case EMPTY_CHAR:
			return new Emptytile(x, y);

		default:
			return new Floortile(x, y);
	}
}

void Cell::setChar(char c) {
    displayChar = c;
}

std::ostream &operator<<(std::ostream &out, const Cell &c) {
    return out << c.displayChar;
}
