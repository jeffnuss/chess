/*
 * Facade.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <cassert>

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

unordered_set<BoardPosition> Facade::GetValidMoves(const BoardPosition & positionToCheck) const
{
	Piece * pieceToCheck = boardPtr->GetPiece(positionToCheck);
	unordered_set<BoardPosition> possibleMoves;
	if (pieceToCheck != NULL)
	{
		possibleMoves = pieceToCheck->GetLegalMoves(positionToCheck, boardPtr);
		CheckForCheck(possibleMoves);
		CheckForCheckMate(possibleMoves);
	}

	return possibleMoves;
}

bool Facade::CheckForCheck(const std::unordered_set<BoardPosition> & possibleMoves) const
{
	
}

bool Facade::CheckForCheckMate(const std::unordered_set<BoardPosition> & possibleMoves) const
{

}

Piece * Facade::MovePiece(const BoardPosition & moveFrom, const BoardPosition & moveTo)
{
	assert (!(moveFrom == moveTo));

	Piece * temp = boardPtr->GetPiece(moveFrom);
	if (boardPtr->GetPiece(moveTo) != NULL)
	{
		boardPtr->ClearCell(moveFrom);
		boardPtr->DeletePiece(moveTo);
	}

	else
	{

		boardPtr->ClearCell(moveFrom);
	}

	boardPtr->SetPiece(moveTo, temp);

	return temp;
}

#ifndef NDEBUG
bool Facade::Test(ostream & os)
{
	bool success = true;

	Facade testFacade;

	TEST(testFacade.MovePiece(BoardPosition(1,0), BoardPosition(2,0)) == testFacade.boardPtr->GetPiece(BoardPosition(2,0)));

	return success;
}
#endif
