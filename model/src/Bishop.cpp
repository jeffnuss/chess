/*
 * Bishop.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/Bishop.h"

using namespace std;

Bishop::Bishop(const int color) : Piece(Piece::BISHOP, color)
{
}

unordered_set<BoardPosition> Bishop::GetLegalMoves(const BoardPosition & currentPiecePosition,
	const Board * currentBoardPtr) const
{
	unordered_set<BoardPosition> legalMoves;
	BoardPosition tempPos = currentPiecePosition;
	
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

	return legalMoves;
}
