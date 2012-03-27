/*
 * ChessController.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include "../inc/ChessController.h"
#include <iostream>

ChessController::ChessController()
{
	// TODO Auto-generated constructor stub

}

ChessController::~ChessController()
{
	delete view;
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
		view->PlacePiece(1, i, B_PAWN);
		view->PlacePiece(6, i, W_PAWN);
	}

	view->PlacePiece(0, 1, B_KNIGHT);
	view->PlacePiece(7, 1, W_KNIGHT);
	view->PlacePiece(0, 6, B_KNIGHT);
	view->PlacePiece(7, 6, W_KNIGHT);

	for (int i = 0; i < 2; i++)
	{
		view->PlacePiece(1, i, B_ROOK);
		view->PlacePiece(6, i, W_ROOK);
	}
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
	this->view = view;
}
