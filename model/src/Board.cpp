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
	boardArray = new Piece[8][8];
	this->Reset();
}

Board::~Board() 
{
	for (int i = 0; i < 7; i++)
	{
		delete[] boardArray[i];
	}
	delete[] boardArray;
}

void Board::Reset()
{
//	boardArray.clear();

	for (int i = 0; i < 7; i++)
	{
		delete boardArray[i];
		for (int j = 0; j < 7; j++)
		{
			boardArray[i][j] = NULL;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		boardArray[i][1] = new Pawn(Piece::PAWN, Piece::BLACK);
		boardArray[i][6] = new Pawn(Piece::PAWN, Piece::WHITE);
	}



}

#ifndef NDEBUG
    bool Board::Test(std::ostream & os)
    {
    	bool success = true;

    	Board testBoard;

//    	TEST(testBoard.boardArray[0][1] == Pawn(Piece::PAWN, Piece::BLACK));
//    	TEST(testBoard.boardArray[1][1] == Pawn(Piece::PAWN, Piece::BLACK));
//    	TEST(testBoard.boardArray[2][1] == Pawn(Piece::PAWN, Piece::BLACK));
//    	TEST(testBoard.boardArray[3][1] == Pawn(Piece::PAWN, Piece::BLACK));
//    	TEST(testBoard.boardArray[4][1] == Pawn(Piece::PAWN, Piece::BLACK));
//    	TEST(testBoard.boardArray[5][1] == Pawn(Piece::PAWN, Piece::BLACK));
//    	TEST(testBoard.boardArray[6][1] == Pawn(Piece::PAWN, Piece::BLACK));
//    	TEST(testBoard.boardArray[7][1] == Pawn(Piece::PAWN, Piece::BLACK));
//    	TEST(testBoard.boardArray[0][6] == Pawn(Piece::PAWN, Piece::WHITE));
//    	TEST(testBoard.boardArray[1][6] == Pawn(Piece::PAWN, Piece::WHITE));
//    	TEST(testBoard.boardArray[2][6] == Pawn(Piece::PAWN, Piece::WHITE));
//    	TEST(testBoard.boardArray[3][6] == Pawn(Piece::PAWN, Piece::WHITE));
//    	TEST(testBoard.boardArray[4][6] == Pawn(Piece::PAWN, Piece::WHITE));
//    	TEST(testBoard.boardArray[5][6] == Pawn(Piece::PAWN, Piece::WHITE));
//    	TEST(testBoard.boardArray[6][6] == Pawn(Piece::PAWN, Piece::WHITE));
//    	TEST(testBoard.boardArray[7][6] == Pawn(Piece::PAWN, Piece::WHITE));


    	return success;
    }
#endif
