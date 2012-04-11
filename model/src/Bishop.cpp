/*
 * Bishop.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/Bishop.h"
#include "UnitTest.h"

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

#ifndef NDEBUG
bool Bishop::Test(ostream & os)
{
	bool success = true;

	Board * testBoard = new Board();
	testBoard->Reset();
	Bishop testBishop(Piece::WHITE);

	testBoard->SetPiece(BoardPosition(2,3), Piece::BISHOP, Piece::WHITE);
	testBoard->SetPiece(BoardPosition(2, 3), testBoard->GetPiece(BoardPosition(7, 2)));
	testBoard->ClearCell(BoardPosition(7, 2));
	unordered_set<BoardPosition> testMoves = testBishop.GetLegalMoves(BoardPosition(2, 3), testBoard);
	unordered_set<BoardPosition> testMovesAnswer = {BoardPosition(1, 2), BoardPosition(1, 4),
			BoardPosition(3, 2), BoardPosition(4, 1), BoardPosition(5, 0), BoardPosition(3, 4),
			BoardPosition(4, 5), BoardPosition(5, 6)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(2, 4), testBoard->GetPiece(BoardPosition(1, 4)));
	testBoard->ClearCell(BoardPosition(1, 4));
	testMoves = testBishop.GetLegalMoves(BoardPosition(2,3), testBoard);
	testMovesAnswer = {BoardPosition(1, 2), BoardPosition(1, 4),
			BoardPosition(3, 2), BoardPosition(4, 1), BoardPosition(5, 0), BoardPosition(3, 4),
			BoardPosition(4, 5), BoardPosition(5, 6), BoardPosition(0, 5)};

	testBoard->SetPiece(BoardPosition(4, 5), testBoard->GetPiece(BoardPosition(6, 5)));
	testBoard->ClearCell(BoardPosition(6, 5));
	testMoves = testBishop.GetLegalMoves(BoardPosition(2,3), testBoard);
	testMovesAnswer = {BoardPosition(1, 2), BoardPosition(1, 4),
			BoardPosition(3, 2), BoardPosition(4, 1), BoardPosition(5, 0),
			BoardPosition(3, 4), BoardPosition(0, 5)};

	delete testBoard;
	return success;
}
#endif
