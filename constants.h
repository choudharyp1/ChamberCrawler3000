/* a2hardy, a3rock, p2choudh
 * March 28, 2017
 *
 * CS246 - A5 - cc3k-villian - floor.cc
 */

#ifndef _CONSTANTS_
#define _CONSTANTS_
#include <string>

// game state
const int GAME_OVER = 2;
const int GAME_WON = 1;
const int CONTINUE = 0;

// game generation
const int NUM_LEVELS   = 5;
const int NUM_CHAMBERS = 5;
const int FLOOR_HEIGHT = 25;
const int FLOOR_WIDTH  = 79;

// floor generation
const int NUM_POTIONS = 10;
const int NUM_GOLD = 10;
const int NUM_ENEMIES = 20;

// character specific
const int GOBLIN_GOLD_BONUS = 5;
const int TROLL_HP_BONUS = 5;
const int VAMPIRE_HP_BONUS = 5;
const float DROW_EFFECT_X = 1.5;

// char representations for objects on the board
const char FLOOR_CHAR = '.';
const char NSWALL_CHAR = '|';
const char EWWALL_CHAR = '-';
const char STAIR_CHAR = '\\';
const char PASSAGE_CHAR = '#';
const char DOORWAY_CHAR = '+';
const char EMPTY_CHAR = ' ';

const char PLAYER_CHAR = '@';

const char HUMAN_CHAR = 'H';
const char DWARF_CHAR = 'W';
const char ELF_CHAR = 'E';
const char ORC_CHAR = 'O';
const char MERCHANT_CHAR = 'M';
const char DRAGON_CHAR = 'D';
const char HALFLING_CHAR = 'L';

const char POTION_CHAR = 'P';
const char GOLD_CHAR = 'G';

// gold string representations
const std::string SP = "SP";
const std::string NP = "NP";
const std::string MH = "MH";
const std::string DH = "DH";

// potion string representations
const std::string RH = "RH";
const std::string BA = "BA";
const std::string BD = "BD";
const std::string PH = "PH";
const std::string WA = "WA";
const std::string WD = "WD";



#endif
