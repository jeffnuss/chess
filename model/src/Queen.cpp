/*
 * Queen.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/Queen.h"

using namespace std;

Queen::Queen(const int color) : Piece(Piece::QUEEN, color)
{
}

unordered_set<BoardPosition> Queen::GetLegalMoves(const BoardPosition & currentPiecePosition,
	const Board * currentBoardPtr) const
{
	unordered_set<BoardPosition> legalMoves;
	BoardPosition tempPos = currentPiecePosition;

	// Check diagonal
	while (tempPos.MoveDownLeft()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));
	tempPos = currentPiecePosition;
	while (tempPos.MoveDownRight()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));
	tempPos = currentPiecePosition;
	while (tempPos.MoveUpLeft()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));
	tempPos = currentPiecePosition;
	while (tempPos.MoveUpRight()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));
	tempPos = currentPiecePosition;
	while (tempPos.MoveUp()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));

	// Check straight
	tempPos = currentPiecePosition;
	while (tempPos.MoveDown()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));
	tempPos = currentPiecePosition;
	while (tempPos.MoveLeft()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));
	tempPos = currentPiecePosition;
	while (tempPos.MoveRight()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));

	return legalMoves;
}
