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
	gameSaver = NULL;
	whoseTurnIsIt = Piece::WHITE;
	checkmate = false;
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
	if (gameSaver != NULL)
	{
		delete gameHistory;
		gameHistory = new MoveHistory;
		delete gameSaver;
		gameSaver = NULL;
	}
	whoseTurnIsIt = Piece::WHITE;
	stalemate = false;
	checkmate = false;
}

unordered_set<BoardPosition> Facade::GetValidMoves(const BoardPosition & positionToCheck)
{
	Piece * pieceToCheck = boardPtr->GetPiece(positionToCheck);
	unordered_set<BoardPosition> possibleMoves;

	if (!checkmate
			&& !stalemate
			&& pieceToCheck != NULL
			&& pieceToCheck->GetColor() == whoseTurnIsIt)
	{
		possibleMoves = pieceToCheck->GetLegalMoves(positionToCheck, boardPtr);
		WillKingBeInCheck(positionToCheck, possibleMoves);
	}

	return possibleMoves;
}

bool Facade::CheckForCheck(int colorToCheck) const
{
	bool isKingInCheck = false;
	BoardPosition tempPos;

	if (colorToCheck == Piece::BLACK)
	{
		tempPos = boardPtr->GetBlackKingPostion();
	}
	else
	{
		tempPos = boardPtr->GetWhiteKingPostion();
	}

	if (CheckStraight(tempPos, colorToCheck)
			|| CheckDiagonal(tempPos, colorToCheck)
			|| CheckKnightPositions(tempPos, colorToCheck)
			|| CheckKingPositions(tempPos, colorToCheck))
	{
		isKingInCheck = true;
	}

	return isKingInCheck;
}

bool Facade::CheckStraight(BoardPosition & currentKingPos, const int colorToCheck) const
{
	BoardPosition tempPos = currentKingPos;

	while (tempPos.MoveUp() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForStraightAttack(boardPtr->GetPiece(tempPos), colorToCheck))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveRight() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForStraightAttack(boardPtr->GetPiece(tempPos), colorToCheck))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveDown() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForStraightAttack(boardPtr->GetPiece(tempPos), colorToCheck))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveLeft() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForStraightAttack(boardPtr->GetPiece(tempPos), colorToCheck))
	{
		return true;
	}

	return false;
}

bool Facade::CheckForStraightAttack(const Piece * tempPiece, const int colorToCheck) const
{
	if (tempPiece->GetColor() != colorToCheck
			&& (tempPiece->GetType() == Piece::ROOK
				|| tempPiece->GetType() == Piece::QUEEN))
	{
		return true;
	}
	return false;
}

bool Facade::CheckDiagonal(BoardPosition & currentKingPos, const int colorToCheck) const
{
	BoardPosition tempPos = currentKingPos;

	while (tempPos.MoveUpRight() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForDiagonalAttack(boardPtr->GetPiece(tempPos), colorToCheck))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveDownRight() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForDiagonalAttack(boardPtr->GetPiece(tempPos), colorToCheck))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveDownLeft() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForDiagonalAttack(boardPtr->GetPiece(tempPos), colorToCheck))
	{
		return true;
	}

	tempPos = currentKingPos;
	while (tempPos.MoveUpLeft() && boardPtr->GetPiece(tempPos) == NULL);
	if (boardPtr->GetPiece(tempPos) != NULL
			&& CheckForDiagonalAttack(boardPtr->GetPiece(tempPos), colorToCheck))
	{
		return true;
	}

	// Add special check for pawn attacks
	tempPos = currentKingPos;
	tempPos.MoveUpRight();
	Piece * tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::PAWN)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveUpLeft();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::PAWN)
	{
		return true;
	}


	tempPos = currentKingPos;
	tempPos.MoveDownRight();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::PAWN)
	{
		return true;
	}


	tempPos = currentKingPos;
	tempPos.MoveDownLeft();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::PAWN)
	{
		return true;
	}


	return false;
}

bool Facade::CheckForDiagonalAttack(const Piece * tempPiece, const int colorToCheck) const
{
	if (tempPiece->GetColor() != colorToCheck
			&& (tempPiece->GetType() == Piece::BISHOP
				|| tempPiece->GetType() == Piece::QUEEN))
	{
		return true;
	}
	return false;
}

bool Facade::CheckKnightPositions(BoardPosition & currentKingPos, const int colorToCheck) const
{
	BoardPosition tempPos = currentKingPos;
	Piece * tempPiece;

	if (tempPos.MoveUpRight()
			&& tempPos.MoveUp())
	{
		tempPiece = boardPtr->GetPiece(tempPos);
		if (tempPiece != NULL
				&& tempPiece->GetColor() != colorToCheck
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
				&& tempPiece->GetColor() != colorToCheck
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
				&& tempPiece->GetColor() != colorToCheck
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
				&& tempPiece->GetColor() != colorToCheck
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
				&& tempPiece->GetColor() != colorToCheck
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
				&& tempPiece->GetColor() != colorToCheck
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
				&& tempPiece->GetColor() != colorToCheck
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
				&& tempPiece->GetColor() != colorToCheck
				&& tempPiece->GetType() == Piece::KNIGHT)
		{
			return true;
		}
	}

	return false;
}

bool Facade::CheckKingPositions(BoardPosition & currentKingPos, const int colorToCheck) const
{
	BoardPosition tempPos = currentKingPos;
	Piece * tempPiece;

	// Add special check for kings
	tempPos = currentKingPos;
	tempPos.MoveDown();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::KING)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveDownLeft();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::KING)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveLeft();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::KING)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveUpLeft();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::KING)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveUp();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::KING)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveUpRight();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::KING)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveRight();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::KING)
	{
		return true;
	}

	tempPos = currentKingPos;
	tempPos.MoveDownRight();
	tempPiece = boardPtr->GetPiece(tempPos);
	if (tempPiece != NULL
			&& tempPiece->GetColor() != colorToCheck
			&& tempPiece->GetType() == Piece::KING)
	{
		return true;
	}

	return false;
}

bool Facade::WillKingBeInCheck(const BoardPosition & originalPosition,
		unordered_set<BoardPosition> & possibleMoves)
{
	bool inCheck = false;
	unordered_set<BoardPosition>::iterator iter = possibleMoves.begin();
	unordered_set<BoardPosition>::iterator iterEnd = possibleMoves.end();
	unordered_set<BoardPosition> toDelete;

	while (iter != iterEnd)
	{
		int row = iter->GetRow();
		int col = iter->GetCol();
		MovePiece(originalPosition, *iter);
		if (CheckForCheck(whoseTurnIsIt ^ 1))
		{
			toDelete.insert(*iter);
			inCheck = true;
		}
		UndoLastMove();
		iter++;
	}

	unordered_set<BoardPosition>::iterator deleteIter = toDelete.begin();
	unordered_set<BoardPosition>::iterator deleteIterEnd = toDelete.end();

	while (deleteIter != deleteIterEnd)
	{
		possibleMoves.erase(*deleteIter);
		deleteIter++;
	}

	return inCheck;
}

bool Facade::CheckForCheckmate(const int colorToCheck)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Piece * tempPiece = boardPtr->GetPiece(BoardPosition(i, j));
			unordered_set<BoardPosition> possibleMoves =
					GetValidMoves(BoardPosition(i, j));
			if (tempPiece != NULL
					&& tempPiece->GetColor() == colorToCheck
					&& !possibleMoves.empty())
			{
				return false;
			}
		}
	}

	if (CheckForCheck(colorToCheck))
	{
		checkmate = true;
		return true;
	}
	else
	{
		stalemate = true;
		return false;
	}
}

Piece * Facade::MovePiece(const BoardPosition & moveFrom, const BoardPosition & moveTo)
{
	//assert (!(moveFrom == moveTo));

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
	checkmate = stalemate = false;
	return lastMove;
}

void Facade::SwitchTurns()
{
	whoseTurnIsIt ^= 1;
}

void Facade::SaveGameAs(const string & fileName)
{
	if (fileName != "")
	{
		gameSaver = new GameSaver(fileName);
		gameSaver->SaveGameAs(fileName, boardPtr, gameHistory);
	}
}

bool Facade::SaveGame() const
{
	if (gameSaver != NULL)
	{
		gameSaver->SaveGame(boardPtr, gameHistory);
		return true;
	}

	return false;
}

bool Facade::LoadGame(const string & filePath) const
{
	NewGame();
	delete boardPtr;
	boardPtr = new Board();
	GameLoader * loader = new GameLoader();
	loader->LoadGame(filePath, boardPtr, gameHistory);



}


bool Facade::AnyMovesMadeYet() const
{
	return !gameHistory->IsEmpty();
}

int Facade::WhoseTurnIsIt() const
{
	return whoseTurnIsIt;
}

bool Facade::ShouldIHighlighThisCell(const BoardPosition & positionToCheck) const
{
	Piece * tempPiece = boardPtr->GetPiece(positionToCheck);
	if (tempPiece == NULL
			|| checkmate
			|| stalemate)
	{
		return false;
	}
	return tempPiece->GetColor() == whoseTurnIsIt;
}

bool Facade::Stalemate() const
{
	return stalemate;
}

#ifndef NDEBUG
bool Facade::Test(ostream & os)
{
	bool success = true;

	Facade testFacade;
	testFacade.NewGame();

	TEST(testFacade.MovePiece(BoardPosition(6,5), BoardPosition(5,5)) == testFacade.boardPtr->GetPiece(BoardPosition(5,5)));
	TEST(testFacade.MovePiece(BoardPosition(1,4), BoardPosition(2,4)) == testFacade.boardPtr->GetPiece(BoardPosition(2,4)));
	TEST(testFacade.MovePiece(BoardPosition(6,2), BoardPosition(5,2)) == testFacade.boardPtr->GetPiece(BoardPosition(5,2)));
	TEST(testFacade.MovePiece(BoardPosition(0,3), BoardPosition(4,7)) == testFacade.boardPtr->GetPiece(BoardPosition(4,7)));
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(4,7))->GetType() == Piece::QUEEN);
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(4,7))->GetColor() == Piece::BLACK);
	TEST(testFacade.MovePiece(BoardPosition(6,6), BoardPosition(5,6)) == testFacade.boardPtr->GetPiece(BoardPosition(5,6)));
	TEST(testFacade.MovePiece(BoardPosition(4,7), BoardPosition(5,6)) == testFacade.boardPtr->GetPiece(BoardPosition(5,6)));
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(6,7))->GetType() == Piece::PAWN);
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(6,7))->GetColor() == Piece::WHITE);

	unordered_set<BoardPosition> cornerPawnCheck = {BoardPosition(5,6)};
	unordered_set<BoardPosition> cornerPawnCheck1 = testFacade.GetValidMoves(BoardPosition(6,7));
	TEST(testFacade.WillKingBeInCheck(BoardPosition(6,7), cornerPawnCheck1) == false);
	TEST(testFacade.GetValidMoves(BoardPosition(6,7)) == cornerPawnCheck);

	testFacade.NewGame();
	testFacade.MovePiece(BoardPosition(6,4), BoardPosition(4,4));
	testFacade.MovePiece(BoardPosition(1,4), BoardPosition(3,4));
	testFacade.MovePiece(BoardPosition(7,4), BoardPosition(6,4));
	testFacade.MovePiece(BoardPosition(0,4), BoardPosition(1,4));
	testFacade.MovePiece(BoardPosition(6,4), BoardPosition(5,3));
	testFacade.MovePiece(BoardPosition(1,4), BoardPosition(2,5));
	testFacade.MovePiece(BoardPosition(5,3), BoardPosition(4,2));
	testFacade.MovePiece(BoardPosition(2,5), BoardPosition(3,6));
	testFacade.MovePiece(BoardPosition(4,2), BoardPosition(3,3));
	testFacade.MovePiece(BoardPosition(3,6), BoardPosition(4,5));
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(3,4))->GetType() == Piece::PAWN);
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(3,4))->GetColor() == Piece::BLACK);
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(3,3))->GetType() == Piece::KING);
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(3,3))->GetColor() == Piece::WHITE);
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(4,5))->GetType() == Piece::KING);
	TEST(testFacade.boardPtr->GetPiece(BoardPosition(4,5))->GetColor() == Piece::BLACK);

	unordered_set<BoardPosition> kingCheck1 = testFacade.GetValidMoves(BoardPosition(3,3));
	unordered_set<BoardPosition> kingCheck2 = {BoardPosition(4,2)};
	TEST(kingCheck1 == kingCheck2);

	testFacade.NewGame();
	testFacade.MovePiece(BoardPosition(6,4), BoardPosition(4,5));
	testFacade.MovePiece(BoardPosition(1,0), BoardPosition(3,0));
	testFacade.MovePiece(BoardPosition(7,3), BoardPosition(3,7));
	testFacade.MovePiece(BoardPosition(0,0), BoardPosition(2,0));
	testFacade.MovePiece(BoardPosition(3,7), BoardPosition(3,0));
	testFacade.MovePiece(BoardPosition(1,7), BoardPosition(3,7));
	testFacade.MovePiece(BoardPosition(3,0), BoardPosition(1,2));
	testFacade.MovePiece(BoardPosition(2,0), BoardPosition(2,7));
	testFacade.MovePiece(BoardPosition(6,7), BoardPosition(4,7));
	testFacade.MovePiece(BoardPosition(1,5), BoardPosition(2,5));
	testFacade.MovePiece(BoardPosition(1,2), BoardPosition(1,3));
	testFacade.MovePiece(BoardPosition(0,4), BoardPosition(1,5));
	testFacade.MovePiece(BoardPosition(1,3), BoardPosition(1,1));
	testFacade.MovePiece(BoardPosition(0,3), BoardPosition(5,3));
	testFacade.MovePiece(BoardPosition(1,1), BoardPosition(0,1));
	testFacade.MovePiece(BoardPosition(5,3), BoardPosition(1,7));
	testFacade.MovePiece(BoardPosition(0,1), BoardPosition(0,2));
	testFacade.MovePiece(BoardPosition(1,5), BoardPosition(2,6));
	testFacade.MovePiece(BoardPosition(0,2), BoardPosition(2,4));

	TEST(!testFacade.CheckForCheck(Piece::BLACK));
	TEST(!testFacade.CheckForCheckmate(Piece::BLACK));
	TEST(testFacade.stalemate == testFacade.Stalemate());
	TEST(testFacade.stalemate);


	return success;
}
#endif
