/*
 * ChessController.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include "../inc/ChessController.h"

ChessController::ChessController()
{
	facadePtr = new Facade;
}

ChessController::~ChessController()
{
	delete facadePtr;
}

void ChessController::on_CellSelected(int row, int col, int button)
{

}

void ChessController::on_DragStart(int row,int col)
{

}

bool ChessController::on_DragEnd(int row,int col)
{

}

void ChessController::on_NewGame()
{
	for (int i = 0; i < 8; i++)
	{
		viewPtr->PlacePiece(1, i, B_PAWN);
		viewPtr->PlacePiece(6, i, W_PAWN);
	}

	viewPtr->PlacePiece(0, 0, B_ROOK);
	viewPtr->PlacePiece(7, 0, W_ROOK);
	viewPtr->PlacePiece(0, 7, B_ROOK);
	viewPtr->PlacePiece(7, 7, W_ROOK);
	viewPtr->PlacePiece(0, 1, B_KNIGHT);
	viewPtr->PlacePiece(7, 1, W_KNIGHT);
	viewPtr->PlacePiece(0, 6, B_KNIGHT);
	viewPtr->PlacePiece(7, 6, W_KNIGHT);
	viewPtr->PlacePiece(0, 2, B_BISHOP);
	viewPtr->PlacePiece(7, 2, W_BISHOP);
	viewPtr->PlacePiece(0, 5, B_BISHOP);
	viewPtr->PlacePiece(7, 5, W_BISHOP);
	viewPtr->PlacePiece(0, 3, B_QUEEN);
	viewPtr->PlacePiece(7, 3, W_QUEEN);
	viewPtr->PlacePiece(0, 4, B_KING);
	viewPtr->PlacePiece(7, 4, W_KING);

	facadePtr->NewGame();
}

void ChessController::on_SaveGame()
{

}

void ChessController::on_SaveGameAs()
{

}

void ChessController::on_LoadGame()
{

}

void ChessController::on_UndoMove()
{

}

void ChessController::on_QuitGame()
{

}

void ChessController::on_TimerEvent()
{

}

void ChessController::SetView(IChessView* view)
{
	this->viewPtr = view;
}
