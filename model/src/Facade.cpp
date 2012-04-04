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

set<BoardPosition> Facade::GetValidMoves(const BoardPosition & positionToCheck) const
{
	Piece pieceToCheck = boardPtr->GetPiece(positionToCheck);
	unordered_set possibleMoves;
	if (pieceToCheck != NULL)
	{
		possibleMoves = pieceToCheck.GetLegalMoves();
		CheckForCheck(possibleMoves);
		CheckForCheckMate(possibleMoves);
	}

	return possibleMoves;
}

void CheckForCheck(BoardPosition & positionToCheck) const
{
	
}

void CheckForCheckMate(BBoardPosition & positionToCheck) const
{

}
