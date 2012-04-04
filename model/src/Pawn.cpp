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
	if (currentPiecePosition.GetRow() == 1 && this->pieceColor == Piece::BLACK)
	{
		 BoardPosition tempPos = currentPiecePosition;
		 tempPos.MoveDown();
		 legalMoves.insert(tempPos);
		 tempPos.MoveDown();
		 legalMoves.insert(tempPos);
	}
	else if (currentPiecePosition.GetRow() == 6 && this->pieceColor == Piece::WHITE)
	{
		 BoardPosition tempPos = currentPiecePosition;
		 tempPos.MoveUp();
		 legalMoves.insert(tempPos);
		 tempPos.MoveUp();
		 legalMoves.insert(tempPos);
	}

	return legalMoves;
}
