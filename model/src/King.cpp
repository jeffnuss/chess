/*
 * King.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/King.h"
#include "UnitTest.h"

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

#ifndef NDEBUG
bool King::Test(ostream & os)
{
	bool success = true;

	Board * testBoard = new Board();
	testBoard->Reset();
	King testKing(Piece::WHITE);

	testBoard->SetPiece(BoardPosition(3, 3), testBoard->GetPiece(BoardPosition(7, 4)));
	testBoard->ClearCell(BoardPosition(7, 4));
	unordered_set<BoardPosition> testMoves = testKing.GetLegalMoves(BoardPosition(3, 3), testBoard);
	unordered_set<BoardPosition> testMovesAnswer = {BoardPosition(3, 2), BoardPosition(4, 2),
			BoardPosition(4, 3), BoardPosition(4, 4), BoardPosition(3, 4),
			BoardPosition(2, 4), BoardPosition(2, 3), BoardPosition(2, 2)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(2, 4), testBoard->GetPiece(BoardPosition(1, 4)));
	testBoard->ClearCell(BoardPosition(1, 4));
	testMoves = testKing.GetLegalMoves(BoardPosition(3, 3), testBoard);
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(4, 3), testBoard->GetPiece(BoardPosition(6, 3)));
	testBoard->ClearCell(BoardPosition(6, 3));
	testMovesAnswer = {BoardPosition(3, 2), BoardPosition(4, 2),
			BoardPosition(4, 4), BoardPosition(3, 4),
			BoardPosition(2, 4), BoardPosition(2, 3), BoardPosition(2, 2)};
	testMoves = testKing.GetLegalMoves(BoardPosition(3, 3), testBoard);
	TEST(testMoves == testMovesAnswer);

	delete testBoard;
	return success;
}
#endif
