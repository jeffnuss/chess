/*
 * Facade.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <cassert>

#include "../inc/Facade.h"

using namespace std;

Facade::Facade()
{
	boardPtr = new Board;
	gameHistory = new MoveHistory;
	whoseTurnIsIt = Piece::BLACK;
}

Facade::~Facade()
{
	delete boardPtr;
	delete gameHistory;
	delete gameSaver;
}

void Facade::NewGame()
{
	boardPtr->Reset();
	whoseTurnIsIt = Piece::BLACK;
}

unordered_set<BoardPosition> Facade::GetValidMoves(const BoardPosition & positionToCheck) const
{
	Piece * pieceToCheck = boardPtr->GetPiece(positionToCheck);
	unordered_set<BoardPosition> possibleMoves;

	if (pieceToCheck != NULL && pieceToCheck->GetColor() == whoseTurnIsIt)
	{
		possibleMoves = pieceToCheck->GetLegalMoves(positionToCheck, boardPtr);
		WillKingBeInCheck(possibleMoves);
		CheckForCheckMate(possibleMoves);
	}

	return possibleMoves;
}

bool Facade::CheckForCheck() const
{
	bool isKingInCheck = false;
	BoardPosition tempPos;

	if (whoseTurnIsIt != Piece::WHITE)
	{
		tempPos = boardPtr->GetBlackKingPostion();
	}
	else
	{
		tempPos = boardPtr->GetWhiteKingPostion();
	}

	if (CheckStraight(tempPos)
			|| CheckDiagonal(tempPos)
			|| CheckKnightPositions(tempPos))
	{
		isKingInCheck = true;
	}

	return isKingInCheck;
}

bool Facade::CheckStraight(BoardPosition & currentKingPos) const
{
	BoardPosition tempPos = currentKingPos;

	while (tempPos.MoveUp() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForStraightAttack(boardPtr->GetPiece(tempPos)))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveRight() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForStraightAttack(boardPtr->GetPiece(tempPos)))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveDown() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForStraightAttack(boardPtr->GetPiece(tempPos)))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveLeft() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForStraightAttack(boardPtr->GetPiece(tempPos)))
	{
		return true;
	}

	return false;
}

bool Facade::CheckForStraightAttack(const Piece * tempPiece) const
{
	if (tempPiece->GetColor() != whoseTurnIsIt
			&& (tempPiece->GetType() == Piece::ROOK
				|| tempPiece->GetType() == Piece::QUEEN))
	{
		return true;
	}
	return false;
}

bool Facade::CheckDiagonal(BoardPosition & currentKingPos) const
{
	BoardPosition tempPos = currentKingPos;

	while (tempPos.MoveUpRight() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForDiagonalAttack(boardPtr->GetPiece(tempPos)))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveDownRight() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForDiagonalAttack(boardPtr->GetPiece(tempPos)))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveDownLeft() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForDiagonalAttack(boardPtr->GetPiece(tempPos)))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveUpLeft() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForDiagonalAttack(boardPtr->GetPiece(tempPos)))
	{
		return true;
	}

	// Add special check for pawn attacks
	tempPos = currentKingPos;
	tempPos.MoveUpRight();
	Piece * tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != whoseTurnIsIt
			&& tempPiece->GetType() == Piece::PAWN)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveUpLeft();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != whoseTurnIsIt
			&& tempPiece->GetType() == Piece::PAWN)
	{
		return true;
	}

	return false;
}

bool Facade::CheckForDiagonalAttack(const Piece * tempPiece) const
{
	if (tempPiece->GetColor() != whoseTurnIsIt
			&& (tempPiece->GetType() == Piece::BISHOP
				|| tempPiece->GetType() == Piece::QUEEN))
	{
		return true;
	}
	return false;
}

bool Facade::CheckKnightPositions(BoardPosition & currentKingPos) const
{
	BoardPosition tempPos = currentKingPos;
	Piece * tempPiece;

	if (tempPos.MoveUpRight()
			&& tempPos.MoveUp())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != whoseTurnIsIt
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	tempPos = currentKingPos;
	if (tempPos.MoveUpRight()
			&& tempPos.MoveRight())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != whoseTurnIsIt
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	tempPos = currentKingPos;
	if (tempPos.MoveDownRight()
			&& tempPos.MoveDown())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != whoseTurnIsIt
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	tempPos = currentKingPos;
	if (tempPos.MoveDownRight()
			&& tempPos.MoveRight())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != whoseTurnIsIt
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	tempPos = currentKingPos;
	if (tempPos.MoveUpLeft()
			&& tempPos.MoveUp())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != whoseTurnIsIt
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	tempPos = currentKingPos;
	if (tempPos.MoveUpLeft()
			&& tempPos.MoveLeft())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != whoseTurnIsIt
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	tempPos = currentKingPos;
	if (tempPos.MoveDownLeft()
			&& tempPos.MoveDown())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != whoseTurnIsIt
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	tempPos = currentKingPos;
	if (tempPos.MoveDownLeft()
			&& tempPos.MoveLeft())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != whoseTurnIsIt
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	return false;
}

bool Facade::WillKingBeInCheck(const std::unordered_set<BoardPosition> & possibleMoves) const
{
	
}

bool Facade::CheckForCheckMate(const std::unordered_set<BoardPosition> & possibleMoves) const
{

}

Piece * Facade::MovePiece(const BoardPosition & moveFrom, const BoardPosition & moveTo)
{
	assert (!(moveFrom == moveTo));

	Piece * pieceToMove = boardPtr->GetPiece(moveFrom);
	Piece * capturedPiece = boardPtr->GetPiece(moveTo);
	Move pieceMove;

	if (capturedPiece != NULL)
	{
		pieceMove = Move(pieceToMove, moveFrom, moveTo, capturedPiece, moveTo);
		boardPtr->DeletePiece(moveTo);
		capturedPiece = NULL;
	}
	else
	{
		pieceMove = Move(pieceToMove, moveFrom, moveTo);
	}

	boardPtr->ClearCell(moveFrom);
	boardPtr->SetPiece(moveTo, pieceToMove);

	SwitchTurns();

	gameHistory->AddMove(pieceMove);

	return pieceToMove;
}

Move Facade::UndoLastMove()
{
	Move lastMove = gameHistory->DeleteLastMove();

	boardPtr->SetPiece(lastMove.GetOriginPosition(),
			boardPtr->GetPiece(lastMove.GetDestinationPosition()));
	boardPtr->ClearCell(lastMove.GetDestinationPosition());

	if (lastMove.GetCapturedPieceType() != -1)
	{
		boardPtr->SetPiece(lastMove.GetCapturedPiecePosition(),
				lastMove.GetCapturedPieceType(), lastMove.GetCapturedPieceColor());
	}

	SwitchTurns();
	return lastMove;
}

void Facade::SwitchTurns()
{
	whoseTurnIsIt ^= 1;
}

void Facade::SaveGameAs(const string & fileName)
{
	gameSaver = new GameSaver(fileName);
	gameSaver->SaveGameAs(fileName, boardPtr, gameHistory);
}

void Facade::SameGame() const
{
	gameSaver->SaveGame(boardPtr, gameHistory);
}

#ifndef NDEBUG
bool Facade::Test(ostream & os)
{
	bool success = true;

	Facade testFacade;
	testFacade.NewGame();

	TEST(testFacade.MovePiece(BoardPosition(1,0), BoardPosition(2,0)) == testFacade.boardPtr->GetPiece(BoardPosition(2,0)));

	return success;
}
#endif
