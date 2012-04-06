/*
 * Board.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include "../inc/Board.h"
#include "../../test/inc/UnitTest.h"
#include "Pawn.h"

using namespace std;

Board::Board() 
{
//	boardArray(8, vector<Piece>(8, 0));
	boardArray = new Piece * [8][8];
	this->Reset();
}

Board::~Board() 
{
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j = 0; j < 7; j++)
//		{
//			delete boardArray[i][j];
//		}
//	}
//	delete[] boardArray;
}

void Board::Reset()
{
//	boardArray.clear();

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//delete boardArray[i][j];
			boardArray[i][j] = NULL;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		boardArray[1][i] = new Pawn(Piece::PAWN, Piece::BLACK);
		boardArray[6][i] = new Pawn(Piece::PAWN, Piece::WHITE);
	}



}

Piece * Board::GetPiece(const BoardPosition & positionToCheck) const
{
	return boardArray[positionToCheck.GetRow()][positionToCheck.GetCol()];
}

void Board::SetPiece(const BoardPosition & positionToSet, Piece * pieceToSet)
{
	boardArray[positionToSet.GetRow()][positionToSet.GetCol()] = pieceToSet;
}

void Board::ClearCell(const BoardPosition & pieceToDelete)
{
	boardArray[pieceToDelete.GetRow()][pieceToDelete.GetCol()] = NULL;
}

#ifndef NDEBUG
bool Board::Test(std::ostream & os)
{
	bool success = true;

	Board testBoard;

	testBoard.Reset();

	TEST(testBoard.boardArray[1][0]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[1][0]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[1][1]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[1][1]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[1][2]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[1][2]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[1][3]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[1][3]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[1][4]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[1][4]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[1][5]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[1][5]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[1][6]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[1][6]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[1][7]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[1][7]->GetType() == Piece::PAWN);

	TEST(testBoard.boardArray[6][0]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][0]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[6][1]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][1]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[6][2]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][2]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[6][3]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][3]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[6][4]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][4]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[6][5]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][5]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[6][6]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][6]->GetType() == Piece::PAWN);
	TEST(testBoard.boardArray[6][7]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][7]->GetType() == Piece::PAWN);

	TEST(testBoard.GetPiece(BoardPosition(6, 2))->GetColor() == Piece::WHITE);
	TEST(testBoard.GetPiece(BoardPosition(6, 2))->GetType() == Piece::PAWN);
	TEST(testBoard.GetPiece(BoardPosition(1, 6))->GetColor() == Piece::BLACK);
	TEST(testBoard.GetPiece(BoardPosition(1, 6))->GetType() == Piece::PAWN);

	Piece * temp = testBoard.boardArray[6][7];
	testBoard.ClearCell(BoardPosition(6, 7));
	TEST(testBoard.boardArray[6][7] == NULL);

	testBoard.SetPiece(BoardPosition(6, 7), temp);
	TEST(testBoard.boardArray[6][7]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][7]->GetType() == Piece::PAWN);

	return success;
}
#endif
