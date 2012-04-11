/*
 * Knight.cpp
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#include "../inc/Knight.h"
#include "UnitTest.h"

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

#ifndef NDEBUG
bool Knight::Test(ostream & os)
{
	bool success = true;

	Board * testBoard = new Board();
	testBoard->Reset();
	Knight testKnight(Piece::WHITE);

	testBoard->SetPiece(BoardPosition(4,3), Piece::KNIGHT, Piece::WHITE);
	testBoard->SetPiece(BoardPosition(4, 3), testBoard->GetPiece(BoardPosition(7, 1)));
	testBoard->ClearCell(BoardPosition(7, 1));
	unordered_set<BoardPosition> testMoves = testKnight.GetLegalMoves(BoardPosition(4, 3), testBoard);
	unordered_set<BoardPosition> testMovesAnswer = {BoardPosition(3, 1), BoardPosition(2, 2),
			BoardPosition(2, 4), BoardPosition(3, 5), BoardPosition(5, 5),
			BoardPosition(5, 1)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(5, 5), testBoard->GetPiece(BoardPosition(6, 5)));
	testBoard->ClearCell(BoardPosition(6, 5));
	testMoves = testKnight.GetLegalMoves(BoardPosition(4, 3), testBoard);
	testMovesAnswer = {BoardPosition(3, 1), BoardPosition(2, 2),
				BoardPosition(2, 4), BoardPosition(3, 5), BoardPosition(5, 1)};
	TEST(testMoves == testMovesAnswer);

	testBoard->SetPiece(BoardPosition(2, 4), testBoard->GetPiece(BoardPosition(1, 4)));
	testBoard->ClearCell(BoardPosition(1, 4));
	testMoves = testKnight.GetLegalMoves(BoardPosition(4, 3), testBoard);
	TEST(testMoves == testMovesAnswer);

	delete testBoard;
	return success;
}
#endif
