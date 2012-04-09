/*
 * ChessController.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <unordered_set>

#include "../inc/ChessController.h"

using namespace std;

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
	BoardPosition newSelectedCell(row, col);

	// Check to see if the newSelectedCell was highlighted
	if (currentHighlightedCells.find(newSelectedCell) != currentHighlightedCells.end())
	{
		Piece * pieceToMove = facadePtr->MovePiece(currentSelectedCell, newSelectedCell);
		MovePiece(currentSelectedCell, newSelectedCell, pieceToMove);
		ClearCurrentHighlights();
		currentHighlightedCells.clear();
		if (facadePtr->CheckForCheck())
		{
			viewPtr->SetStatusBar("Check");
		}
		else
		{
			viewPtr->SetStatusBar("");
		}
	}

	else
	{
		HighlightMoves(newSelectedCell);
	}
	currentSelectedCell = newSelectedCell;
}

void ChessController::HighlightMoves(const BoardPosition & positionToCheck)
{
	ClearCurrentHighlights();

	unordered_set<BoardPosition> possibleMoves = facadePtr->GetValidMoves(positionToCheck);
	unordered_set<BoardPosition>::iterator iter = possibleMoves.begin();
	while (iter != possibleMoves.end())
	{
		viewPtr->HighlightSquare((*iter).GetRow(), (*iter).GetCol(), BLUE_SQUARE);
		iter++;
	}
	currentHighlightedCells = possibleMoves;
}

void ChessController::ClearCurrentHighlights()
{
	unordered_set<BoardPosition>::iterator iter1 = currentHighlightedCells.begin();
	while (iter1 != currentHighlightedCells.end())
	{
		viewPtr->UnHighlightSquare((*iter1).GetRow(), (*iter1).GetCol());
		iter1++;
	}
}

void ChessController::MovePiece(const BoardPosition & moveFrom, const BoardPosition moveTo, const Piece * pieceToMove)
{
	viewPtr->ClearPiece(moveFrom.GetRow(), moveFrom.GetCol());

	ImageName pieceToPlace;
	int pieceColor = pieceToMove->GetColor();
	int pieceType = pieceToMove->GetType();

	pieceToPlace = GetPieceImage(pieceColor, pieceType);

	viewPtr->PlacePiece(moveTo.GetRow(), moveTo.GetCol(), pieceToPlace);
}

ImageName ChessController::GetPieceImage(const int pieceColor, const int pieceType) const
{
	ImageName pieceToPlace;

	if (pieceColor == 0)
	{
		switch (pieceType)
		{
			case 0:
				pieceToPlace = B_PAWN;
				break;
			case 1:
				pieceToPlace = B_KNIGHT;
				break;
			case 2:
				pieceToPlace = B_BISHOP;
				break;
			case 3:
				pieceToPlace = B_ROOK;
				break;
			case 4:
				pieceToPlace = B_QUEEN;
				break;
			case 5:
				pieceToPlace = B_KING;
				break;
		}
	}
	else
	{
		switch (pieceType)
		{
			case 0:
				pieceToPlace = W_PAWN;
				break;
			case 1:
				pieceToPlace = W_KNIGHT;
				break;
			case 2:
				pieceToPlace = W_BISHOP;
				break;
			case 3:
				pieceToPlace = W_ROOK;
				break;
			case 4:
				pieceToPlace = W_QUEEN;
				break;
			case 5:
				pieceToPlace = W_KING;
				break;
		}
	}

	return pieceToPlace;
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
		for (int j = 0; j < 8; j++)
		{
			viewPtr->ClearPiece(i, j);
		}
	}

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
	facadePtr->SaveGameAs("~/cs_240/Chess/test.xml");
}

void ChessController::on_SaveGameAs()
{

}

void ChessController::on_LoadGame()
{

}

void ChessController::on_UndoMove()
{
	ClearCurrentHighlights();

	Move lastMove = facadePtr->UndoLastMove();
	BoardPosition moveOrigin = lastMove.GetOriginPosition();
	BoardPosition moveDestination = lastMove.GetDestinationPosition();
	int capturedPieceType = lastMove.GetCapturedPieceType();

	viewPtr->ClearPiece(moveDestination.GetRow(), moveDestination.GetCol());
	if (capturedPieceType != -1)
	{
		BoardPosition capturedPostion = lastMove.GetCapturedPiecePosition();
		viewPtr->PlacePiece(capturedPostion.GetRow(),
				capturedPostion.GetCol(),
				GetPieceImage(lastMove.GetCapturedPieceColor(), capturedPieceType));
	}

	viewPtr->PlacePiece(lastMove.GetOriginPosition().GetRow(),
			lastMove.GetOriginPosition().GetCol(),
			GetPieceImage(lastMove.GetPieceColor(), lastMove.GetPieceType()));

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
