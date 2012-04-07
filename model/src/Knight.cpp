/*
 * Knight.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/Knight.h"

using namespace std;

Knight::Knight(const int color) : Piece(Piece::KNIGHT, color)
{
}

std::unordered_set<BoardPosition> Knight::GetLegalMoves(const BoardPosition & currentPiecePosition,
		const Board * currentBoardPtr) const
{
	unordered_set<BoardPosition> legalMoves;
	BoardPosition tempPos = currentPiecePosition;

	if (tempPos.MoveDownLeft() && tempPos.MoveDown())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveDownLeft() && tempPos.MoveLeft())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveDownRight() && tempPos.MoveDown())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveDownRight() && tempPos.MoveRight())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveUpLeft() && tempPos.MoveUp())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveUpLeft() && tempPos.MoveLeft())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveUpRight() && tempPos.MoveUp())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	tempPos = currentPiecePosition;

	if (tempPos.MoveUpRight() && tempPos.MoveRight())
	{
		CheckCell(tempPos, currentBoardPtr, legalMoves);
	}

	return legalMoves;
}
