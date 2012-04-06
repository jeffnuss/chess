/*
 * Pawn.cpp
 *
 *  Created on: Apr 2, 2012
 *      Author: jnuss
 */

#include "../inc/Pawn.h"

using namespace std;

Pawn::Pawn(int type, int color) : Piece(type, color)
{
}

Pawn::~Pawn()
{
	// TODO Auto-generated destructor stub
}

   
unordered_set<BoardPosition> Pawn::GetLegalMoves(const BoardPosition & currentPiecePosition,
	const Board * currentBoardPtr) const
{
	unordered_set<BoardPosition> legalMoves;
	BoardPosition tempPos = currentPiecePosition;
	if (this->pieceColor == Piece::BLACK)
	{
		// Make sure to see if you can move up first or else tempPos won't get incremented
		// and ThereIsAPieceInMyWay will return false
		if (!tempPos.MoveDown() || ThereIsAPieceInMyWay(tempPos, currentBoardPtr))
		{
			return legalMoves;
		}
		legalMoves.insert(tempPos);
		if (currentPiecePosition.GetRow() == 1)
		{
			if (!tempPos.MoveDown() || ThereIsAPieceInMyWay(tempPos, currentBoardPtr))
			{
				return legalMoves;
			}
		 	legalMoves.insert(tempPos);
		 }
	}
	else if (this->pieceColor == Piece::WHITE)
	{
		if (!tempPos.MoveUp() || ThereIsAPieceInMyWay(tempPos, currentBoardPtr))
		{
			return legalMoves;
		}
		legalMoves.insert(tempPos);
		if (currentPiecePosition.GetRow() == 6)
		{
			if (!tempPos.MoveUp() || ThereIsAPieceInMyWay(tempPos, currentBoardPtr))
			{
				return legalMoves;
			}
			legalMoves.insert(tempPos);
		}
	}

	return legalMoves;
}

bool Pawn::ThereIsAPieceInMyWay(const BoardPosition & positionToCheck, const Board * boardPtr) const
{
	return (boardPtr->GetPiece(positionToCheck) != NULL);
}
