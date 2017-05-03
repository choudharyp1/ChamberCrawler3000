/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _GOLD_
#define _GOLD_

#include <string>
#include "item.h"
#include "constants.h"

class Player;

class Gold : public Item {
    const std::string displayStr;
public:
    Gold(bool c, int v, std::string d);

    static Gold * create();

    void affect(Player * p) override;    // increases the Player's amount of gold
    void affect(Drow * d) override;
    friend std::ostream &operator<<(std::ostream &out, const Gold &g);
};

#endif
