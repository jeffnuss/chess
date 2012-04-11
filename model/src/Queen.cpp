/*
 * Queen.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/Queen.h"
#include "UnitTest.h"

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


#ifndef NDEBUG
bool Queen::Test(ostream & os)
{
	bool success = true;

	Board * testBoard = new Board();
	testBoard->Reset();
	Queen testQueen(Piece::WHITE);

	testBoard->SetPiece(BoardPosition(4, 3), testBoard->GetPiece(BoardPosition(7, 3)));
	testBoard->ClearCell(BoardPosition(7, 3));
	unordered_set<BoardPosition> testMoves = testQueen.GetLegalMoves(BoardPosition(4, 3), testBoard);
	unordered_set<BoardPosition> testMovesAnswer = {BoardPosition(4, 2), BoardPosition(4, 1), BoardPosition(4, 0),
			BoardPosition(4, 4), BoardPosition(4, 5), BoardPosition(4, 6), BoardPosition(4, 7),
			BoardPosition(3, 3), BoardPosition(2, 3), BoardPosition(1, 3), BoardPosition(5, 3),
			BoardPosition(3 ,4), BoardPosition(2 ,5), BoardPosition(1 ,6),
			BoardPosition(3 ,2), BoardPosition(2 ,1), BoardPosition(1 ,0),
			BoardPosition(5 ,2), BoardPosition(5 ,4)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(5, 5), testBoard->GetPiece(BoardPosition(6, 5)));
	testBoard->ClearCell(BoardPosition(6, 5));
	testMoves = testQueen.GetLegalMoves(BoardPosition(4, 3), testBoard);
	testMovesAnswer = {BoardPosition(4, 2), BoardPosition(4, 1), BoardPosition(4, 0),
			BoardPosition(4, 4), BoardPosition(4, 5), BoardPosition(4, 6), BoardPosition(4, 7),
			BoardPosition(3, 3), BoardPosition(2, 3), BoardPosition(1, 3), BoardPosition(5, 3),
			BoardPosition(3 ,4), BoardPosition(2 ,5), BoardPosition(1 ,6),
			BoardPosition(3 ,2), BoardPosition(2 ,1), BoardPosition(1 ,0),
			BoardPosition(5 ,2), BoardPosition(5 ,4), BoardPosition(6, 5)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(4, 5), testBoard->GetPiece(BoardPosition(5, 5)));
	testBoard->ClearCell(BoardPosition(5, 5));
	testMoves = testQueen.GetLegalMoves(BoardPosition(4, 3), testBoard);
	testMovesAnswer = {BoardPosition(4, 2), BoardPosition(4, 1), BoardPosition(4, 0),
			BoardPosition(4, 4), BoardPosition(3, 3), BoardPosition(2, 3),
			BoardPosition(1, 3), BoardPosition(5, 3), BoardPosition(3 ,4),
			BoardPosition(2 ,5), BoardPosition(1 ,6), BoardPosition(3 ,2),
			BoardPosition(2 ,1), BoardPosition(1 ,0), BoardPosition(5 ,2),
			BoardPosition(5 ,4), BoardPosition(6, 5)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(3, 4), testBoard->GetPiece(BoardPosition(1, 4)));
	testBoard->ClearCell(BoardPosition(1, 4));
	testMoves = testQueen.GetLegalMoves(BoardPosition(4, 3), testBoard);
	testMovesAnswer = {BoardPosition(4, 2), BoardPosition(4, 1), BoardPosition(4, 0),
			BoardPosition(4, 4), BoardPosition(3, 3), BoardPosition(2, 3),
			BoardPosition(1, 3), BoardPosition(5, 3), BoardPosition(3 ,4),
			BoardPosition(3 ,2), BoardPosition(2 ,1), BoardPosition(1 ,0),
			BoardPosition(5 ,2), BoardPosition(5 ,4), BoardPosition(6, 5)};
	TEST(testMoves == testMovesAnswer);

	delete testBoard;
	return success;
}
#endif
