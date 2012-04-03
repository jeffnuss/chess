/*
 * Facade.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include "../inc/Facade.h"

using namespace std;

Facade::Facade()
{
	boardPtr = new Board;
}

Facade::~Facade()
{
	delete boardPtr;
}

void Facade::NewGame()
{
	boardPtr->Reset();
}

set<BoardPosition> Facade::getValidMoves(const BoardPosition & positionToCheck) const
{

}

