/* class for simulating a die to generate an integer random number.

dice(int sides) --	constructor, sides specifies number of "sides"
	for the die, 2 for a coin, 6 for a regular die, etc.

int roll() --	returns the random roll of the die, a (hopefully) uniformly
	distributed random number between 1 and # of sides

int numSides() -- access function, returns # of sides

Modeled after a dice class from Owen Astrachan, Duke University.
A Computer Science Tapestry, McGraw Hill, Custom College Series, © 1997.
Last revised, Cary Matsuoka, 5/30/96  */


#ifndef  DICE_H
#define  DICE_H

#include <stdlib.h>	// random and randomize are inside stdlib.h

using namespace std;
class dice {
public:
	dice(int sides);		// constructor
	int roll();			// return the random roll
	int numSides();		// returns number of sides on die
	int numRolls();
private:
	int mySides;
	int myRollCount;
};								// note semicolon after closing brace of class

dice::dice(int sides)
// postcondition:  all private fields initialized
// randomize() called to set random number generator
{
	srand(time(NULL));
	mySides = sides;
	myRollCount = 0;
}

int dice::numRolls()
{
	return myRollCount;
}

int dice::roll()
// postcondition: # of rolls updated, returns random die roll
{
	myRollCount++;
	return rand() % mySides + 1;
}

int dice::numSides()
// postcondition:  return # of sides of die
{
	return mySides;
}

#endif
