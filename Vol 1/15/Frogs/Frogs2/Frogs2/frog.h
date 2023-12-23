#pragma once

#ifndef FROG_H
#define FROG_H

#include <stdlib.h>
#include <time.h>

using namespace std;

class frog
{
public:
	frog();
	int move();
	int stepCount();
	int getPos();
private:
	int mySteps;
	int myPos;
};

frog::frog()
{
	srand(time(NULL));
	mySteps = 0;
	myPos = 0;
}

int frog::move()
{
	mySteps++;
	if (rand() % 2 == 0)
		myPos++;
	else
		myPos--;
	return myPos;
}

int frog::stepCount()
{
	return mySteps;
}

int frog::getPos()
{
	return myPos;
}


#endif