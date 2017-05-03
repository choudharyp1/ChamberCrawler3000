/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _CHAMBER_
#define _CHAMBER_
#include <vector>

class Floortile;

// class to represent a Chamber in a Floor
class Chamber {
    std::vector<Floortile *> floortiles;     // the Floortiles in the Chamber
public:
    Chamber();
    Chamber(std::vector<Floortile *> floortiles);
    ~Chamber();

    void addTile(Floortile *tile); // adds a Floortile to the chamber
    Floortile *randomCell();       // returns a random cell in the chamber that is valid for a Character to spawn
                                   //   raises exception if there are no valid cells
};

#endif
