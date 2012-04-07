/*
 * Pawn.cpp
 *
 *  Created on: Apr 2, 2012
 *      Author: jnuss
 */

#include "../inc/Pawn.h"
#include "../../test/inc/UnitTest.h"

using namespace std;

Pawn::Pawn(const int color) : Piece(Piece::PAWN, color)
{
}
   
unordered_set<BoardPosition> Pawn::GetLegalMoves(const BoardPosition & currentPiecePosition,
	const Board * currentBoardPtr) const
{
	unordered_set<BoardPosition> legalMoves;
	BoardPosition tempPos = currentPiecePosition;
	if (pieceColor == Piece::BLACK)
	{
		// Make sure to see if you can move up first or else tempPos won't get incremented
		// and ThereIsAPieceInMyWay will return false
		if (tempPos.MoveDown() && !ThereIsAPieceInMyWay(tempPos, currentBoardPtr))
		{
			legalMoves.insert(tempPos);
			if (currentPiecePosition.GetRow() == 1
					&& tempPos.MoveDown()
					&& !ThereIsAPieceInMyWay(tempPos, currentBoardPtr))
			{

				legalMoves.insert(tempPos);

			 }
		}
	}
	else
	{
		if (tempPos.MoveUp() && !ThereIsAPieceInMyWay(tempPos, currentBoardPtr))
		{
			legalMoves.insert(tempPos);
			if (currentPiecePosition.GetRow() == 6
					&& tempPos.MoveUp()
					&& !ThereIsAPieceInMyWay(tempPos, currentBoardPtr))
			{
				legalMoves.insert(tempPos);
			}
		}
	}

	CheckForCaptures(currentPiecePosition, currentBoardPtr, legalMoves);

	return legalMoves;
}

bool Pawn::CheckForCaptures(const BoardPosition & currentPiecePosition,
		const Board * currentBoardPtr, unordered_set<BoardPosition> & legalMoves) const
{
	BoardPosition tempPos = currentPiecePosition;
	if (pieceColor == Piece::BLACK)
	{
		if (tempPos.MoveDownLeft()
				&& currentBoardPtr->GetPiece(tempPos) != NULL
				&& currentBoardPtr->GetPiece(tempPos)->GetColor() != this->pieceColor)
		{
			legalMoves.insert(tempPos);
		}

		tempPos = currentPiecePosition;
		if (tempPos.MoveDownRight()
				&& currentBoardPtr->GetPiece(tempPos) != NULL
				&& currentBoardPtr->GetPiece(tempPos)->GetColor() != this->pieceColor)
		{
			legalMoves.insert(tempPos);
		}
	}

	else
	{
		if (tempPos.MoveUpLeft()
				&& currentBoardPtr->GetPiece(tempPos) != NULL
				&& currentBoardPtr->GetPiece(tempPos)->GetColor() != this->pieceColor)
		{
			legalMoves.insert(tempPos);
		}

		tempPos = currentPiecePosition;
		if (tempPos.MoveUpRight()
				&& currentBoardPtr->GetPiece(tempPos) != NULL
				&& currentBoardPtr->GetPiece(tempPos)->GetColor() != this->pieceColor)
		{
			legalMoves.insert(tempPos);
		}
	}
}

bool Pawn::ThereIsAPieceInMyWay(const BoardPosition & positionToCheck, const Board * boardPtr) const
{
	return (boardPtr->GetPiece(positionToCheck) != NULL);
}

#ifndef NDEBUG
bool Pawn::Test(ostream & os)
{
	bool success = true;

	Board * testBoard = new Board();
	Pawn testPawn(Piece::WHITE);
	
	TEST(testPawn.pieceColor == testPawn.GetColor());
	TEST(testPawn.pieceType == testPawn.GetType());
	TEST(testPawn.ThereIsAPieceInMyWay(BoardPosition(5, 3), testBoard) == false);
	TEST(testPawn.ThereIsAPieceInMyWay(BoardPosition(6, 3), testBoard) == true);
	
	testBoard->SetPiece(BoardPosition(5, 3), Piece::PAWN, Piece::BLACK);
	unordered_set<BoardPosition> testMoves1 = testPawn.GetLegalMoves(BoardPosition(6, 4), testBoard);
	unordered_set<BoardPosition> testMoves2 = {BoardPosition(5, 3), BoardPosition(5, 4), BoardPosition(4, 4)};
	TEST(testMoves1 == testMoves2);

	delete testBoard;
	return success;
}
#endif
