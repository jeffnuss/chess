/*
 * Board.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include "../inc/Board.h"
#include "../../test/inc/UnitTest.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

using namespace std;

Board::Board() 
{
	boardArray = new Piece**[8];
	for (int i = 0; i < 8; ++i)
	{
		boardArray[i] = new Piece *[8];
	}

	for (int i = 0; i < 8; ++i)
	{
	  for (int j = 0; j < 8; ++j)
	  {
		  boardArray[i][j] = NULL;
	  }
	}

	this->Reset();
}

Board::~Board() 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete boardArray[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
	{
		delete[] boardArray[i];
	}

	delete[] boardArray;
}

void Board::Reset()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete boardArray[i][j];
			boardArray[i][j] = NULL;
		}
	}

	for (int i = 0; i < 8; i++)
	{
		boardArray[1][i] = new Pawn(Piece::BLACK);
		boardArray[6][i] = new Pawn(Piece::WHITE);
	}

	boardArray[0][0] = new Rook(Piece::BLACK);
	boardArray[0][1] = new Knight(Piece::BLACK);
	boardArray[0][2] = new Bishop(Piece::BLACK);
	boardArray[0][3] = new Queen(Piece::BLACK);
	boardArray[0][4] = new King(Piece::BLACK);
	boardArray[0][5] = new Bishop(Piece::BLACK);
	boardArray[0][6] = new Knight(Piece::BLACK);
	boardArray[0][7] = new Rook(Piece::BLACK);

	boardArray[7][0] = new Rook(Piece::WHITE);
	boardArray[7][1] = new Knight(Piece::WHITE);
	boardArray[7][2] = new Bishop(Piece::WHITE);
	boardArray[7][3] = new Queen(Piece::WHITE);
	boardArray[7][4] = new King(Piece::WHITE);
	boardArray[7][5] = new Bishop(Piece::WHITE);
	boardArray[7][6] = new Knight(Piece::WHITE);
	boardArray[7][7] = new Rook(Piece::WHITE);
}

Piece * Board::GetPiece(const BoardPosition & positionToCheck) const
{
	return boardArray[positionToCheck.GetRow()][positionToCheck.GetCol()];
}

void Board::SetPiece(const BoardPosition & positionToSet, Piece * pieceToSet)
{
	boardArray[positionToSet.GetRow()][positionToSet.GetCol()] = pieceToSet;
}

Piece * Board::SetPiece(const BoardPosition & positionToSet, const int pieceType, const int pieceColor)
{
	switch (pieceType)
	{
	case Piece::PAWN:
		boardArray[positionToSet.GetRow()][positionToSet.GetCol()] = new Pawn(pieceColor);
		break;
	case Piece::KNIGHT:
		boardArray[positionToSet.GetRow()][positionToSet.GetCol()] = new Knight(pieceColor);
		break;
	case Piece::BISHOP:
		boardArray[positionToSet.GetRow()][positionToSet.GetCol()] = new Bishop(pieceColor);
		break;
	case Piece::ROOK:
		boardArray[positionToSet.GetRow()][positionToSet.GetCol()] = new Rook(pieceColor);
		break;
	case Piece::QUEEN:
		boardArray[positionToSet.GetRow()][positionToSet.GetCol()] = new Queen(pieceColor);
		break;
	case Piece::KING:
		boardArray[positionToSet.GetRow()][positionToSet.GetCol()] = new King(pieceColor);
		break;
	}
	return boardArray[positionToSet.GetRow()][positionToSet.GetCol()];
}

void Board::ClearCell(const BoardPosition & cellToClear)
{
	boardArray[cellToClear.GetRow()][cellToClear.GetCol()] = NULL;
}

void Board::DeletePiece(const BoardPosition & pieceToDelete)
{
	delete boardArray[pieceToDelete.GetRow()][pieceToDelete.GetCol()];
	ClearCell(pieceToDelete);
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

	TEST(testBoard.boardArray[0][0]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[0][0]->GetType() == Piece::ROOK);
	TEST(testBoard.boardArray[0][1]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[0][1]->GetType() == Piece::KNIGHT);
	TEST(testBoard.boardArray[0][2]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[0][2]->GetType() == Piece::BISHOP);
	TEST(testBoard.boardArray[0][3]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[0][3]->GetType() == Piece::QUEEN);
	TEST(testBoard.boardArray[0][4]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[0][4]->GetType() == Piece::KING);
	TEST(testBoard.boardArray[0][5]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[0][5]->GetType() == Piece::BISHOP);
	TEST(testBoard.boardArray[0][6]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[0][6]->GetType() == Piece::KNIGHT);
	TEST(testBoard.boardArray[0][7]->GetColor() == Piece::BLACK);
	TEST(testBoard.boardArray[0][7]->GetType() == Piece::ROOK);

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

	TEST(testBoard.boardArray[7][0]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[7][0]->GetType() == Piece::ROOK);
	TEST(testBoard.boardArray[7][1]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[7][1]->GetType() == Piece::KNIGHT);
	TEST(testBoard.boardArray[7][2]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[7][2]->GetType() == Piece::BISHOP);
	TEST(testBoard.boardArray[7][3]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[7][3]->GetType() == Piece::QUEEN);
	TEST(testBoard.boardArray[7][4]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[7][4]->GetType() == Piece::KING);
	TEST(testBoard.boardArray[7][5]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[7][5]->GetType() == Piece::BISHOP);
	TEST(testBoard.boardArray[7][6]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[7][6]->GetType() == Piece::KNIGHT);
	TEST(testBoard.boardArray[7][7]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[7][7]->GetType() == Piece::ROOK);

	TEST(testBoard.GetPiece(BoardPosition(6, 2))->GetColor() == Piece::WHITE);
	TEST(testBoard.GetPiece(BoardPosition(6, 2))->GetType() == Piece::PAWN);
	TEST(testBoard.GetPiece(BoardPosition(1, 6))->GetColor() == Piece::BLACK);
	TEST(testBoard.GetPiece(BoardPosition(1, 6))->GetType() == Piece::PAWN);

	Piece * temp = testBoard.boardArray[6][7];
	testBoard.ClearCell(BoardPosition(6, 7));
	TEST(testBoard.boardArray[6][7] == NULL);

	testBoard.SetPiece(BoardPosition(6, 7), temp->GetType(), temp->GetColor());
	TEST(testBoard.boardArray[6][7]->GetColor() == Piece::WHITE);
	TEST(testBoard.boardArray[6][7]->GetType() == Piece::PAWN);

	testBoard.DeletePiece(BoardPosition(6, 7));
	Piece * temp2 = testBoard.GetPiece(BoardPosition(6, 7));
	TEST(testBoard.GetPiece(BoardPosition(6, 7)) != temp);

	return success;
}
#endif
