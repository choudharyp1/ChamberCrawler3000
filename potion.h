/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _POTION_
#define _POTION_
#include <string>
#include "item.h"

class Potion : public Item {
    const std::string displayStr;
public:
    Potion(int v, std::string d);

    static Potion * create();

    friend std::ostream &operator<<(std::ostream &out, const Potion &p);
};

#endif
