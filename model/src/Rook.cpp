/*
 * Rook.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/Rook.h"
#include "UnitTest.h"

using namespace std;

Rook::Rook(const int color) : Piece(Piece::ROOK, color)
{
}

std::unordered_set<BoardPosition> Rook::GetLegalMoves(const BoardPosition & currentPiecePosition,
		const Board * currentBoardPtr) const
{
	unordered_set<BoardPosition> legalMoves;
	BoardPosition tempPos = currentPiecePosition;

	while (tempPos.MoveUp()
			&& ContinuousCheck(tempPos, currentBoardPtr, legalMoves));
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
bool Rook::Test(ostream & os)
{
	bool success = true;

	Board * testBoard = new Board();
	testBoard->Reset();
	Rook testRook(Piece::WHITE);

	testBoard->SetPiece(BoardPosition(4, 3), testBoard->GetPiece(BoardPosition(7, 0)));
	testBoard->ClearCell(BoardPosition(7, 0));
	unordered_set<BoardPosition> testMoves = testRook.GetLegalMoves(BoardPosition(4, 3), testBoard);
	unordered_set<BoardPosition> testMovesAnswer = {BoardPosition(4, 2), BoardPosition(4, 1), BoardPosition(4, 0),
			BoardPosition(4, 4), BoardPosition(4, 5), BoardPosition(4, 6), BoardPosition(4, 7),
			BoardPosition(3, 3), BoardPosition(2, 3), BoardPosition(1, 3), BoardPosition(5, 3)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(3, 3), testBoard->GetPiece(BoardPosition(1, 3)));
	testBoard->ClearCell(BoardPosition(1, 3));
	testMoves = testRook.GetLegalMoves(BoardPosition(4, 3), testBoard);
	testMovesAnswer = {BoardPosition(4, 2), BoardPosition(4, 1), BoardPosition(4, 0),
			BoardPosition(4, 4), BoardPosition(4, 5), BoardPosition(4, 6), BoardPosition(4, 7),
			BoardPosition(3, 3), BoardPosition(5, 3)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(4, 4), testBoard->GetPiece(BoardPosition(6, 4)));
	testBoard->ClearCell(BoardPosition(6, 4));
	testMoves = testRook.GetLegalMoves(BoardPosition(4, 3), testBoard);
	testMovesAnswer = {BoardPosition(4, 2), BoardPosition(4, 1), BoardPosition(4, 0),
			BoardPosition(3, 3), BoardPosition(5, 3)};
	TEST(testMoves == testMovesAnswer);

	delete testBoard;
	return success;
}
#endif
