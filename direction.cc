#include "direction.h"

Direction::Direction(std::string s)
{
	if(s == "no")
		x = -1, y = -0;
	else if(s == "so")
		x = +1, y = +0;
	else if(s == "ea")
		x = +0, y = +1;
	else if(s == "we")
		x = -0, y = -1;
	else if(s == "ne")
		x = -1, y = +1;
	else if(s == "nw")
		x = -1, y = -1;
	else if(s == "se")
		x = +1, y = +1;
	else if(s == "sw")
		x = +1, y = -1;

	if(s == "w")
		x = -1, y = -0;
	else if(s == "s")
		x = +1, y = +0;
	else if(s == "d")
		x = +0, y = +1;
	else if(s == "a")
		x = -0, y = -1;
	else if(s == "wd" || s == "dw")
		x = -1, y = +1;
	else if(s == "wa" || s == "aw")
		x = -1, y = -1;
	else if(s == "sd" || s == "ds")
		x = +1, y = +1;
	else if(s == "sa" || s == "as")
		x = +1, y = -1;
}

Direction::Direction(int x, int y) : x{x}, y{y} {}
