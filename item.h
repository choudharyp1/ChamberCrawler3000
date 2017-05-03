/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _ITEM_
#define _ITEM_
#include <string>

class Player;
class Drow;
class Vampire;

class Item {
protected:
    bool collectible;
    const int value;
    const std::string displayStr;
public:
    Item(bool c, int v, std::string s);
    virtual ~Item()=0;

    virtual void affect(Player *p) = 0;         // affects the Player depending on the type of sub class
    virtual void affect(Drow * d) = 0;
    bool isCollectible() const;                 // indicates whether the item is collectible or not
    void makeCollectible();
    std::string getStr() const;
};

#endif
