/*
 * King.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/King.h"

using namespace std;

King::King(const int color) : Piece(Piece::KING, color)
{
}

unordered_set<BoardPosition> King::GetLegalMoves(const BoardPosition & currentPiecePosition,
	const Board * currentBoardPtr) const
{
	unordered_set<BoardPosition> legalMoves;
	BoardPosition tempPos = currentPiecePosition;

	if (tempPos.MoveDown())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveDownLeft())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveLeft())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveUpLeft())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveUp())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveUpRight())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveRight())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveDownRight())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	return legalMoves;
}
