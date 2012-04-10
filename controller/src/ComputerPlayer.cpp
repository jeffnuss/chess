/*
 * ComputerPlayer.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: jnuss
 */

#include "../inc/ComputerPlayer.h"
#include "../../model/inc/Piece.h"

#include <time.h>
#include <stdlib.h>

using namespace std;

ComputerPlayer::ComputerPlayer(int color, Facade * facadePtr, ChessController * controllerPtr)
	: color(color), facadePtr(facadePtr), controllerPtr(controllerPtr)
{
}

ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::on_CellSelected(int row, int col, int button)
{

}

void ComputerPlayer::on_TimerEvent()
{
	if (facadePtr->WhoseTurnIsIt() == color
			&& !facadePtr->Checkmate()
			&& !facadePtr->Stalemate())
	{
		srand(time(NULL));
		int randomRow = rand() % 8;
		int randomCol = rand() % 8;

	//	Piece * tempPiece = facadePtr->GetPiece(BoardPosition(randomRow, randomCol));
		unordered_set<BoardPosition> possibleMoves = facadePtr->GetValidMoves(BoardPosition(randomRow, randomCol));
		while (possibleMoves.empty())
		{
			randomCol = rand() % 8;
			randomRow = rand() % 8;
	//		tempPiece = facadePtr->GetPiece(BoardPosition(randomRow, randomCol));
			possibleMoves = facadePtr->GetValidMoves(BoardPosition(randomRow, randomCol));
		}

		controllerPtr->on_CellSelected(randomRow, randomCol, -1);

		int randomIndex = rand() % possibleMoves.size();

		unordered_set<BoardPosition>::iterator iter = possibleMoves.begin();
		for (int i = 0; i < randomIndex; i++)
		{
			iter++;
		}

		BoardPosition moveToMake = *iter;
		controllerPtr->on_CellSelected(moveToMake.GetRow(), moveToMake.GetCol(), -1);

	}

}
