/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _LOCATION_H_
#define _LOCATION_H_

class Floortile;

struct Location{
	int x;
	int y;
	Floortile *c;
};

#endif
