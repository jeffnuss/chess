/*
 * Facade.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <unordered_set>
#include <iostream>

#include "Board.h"
#include "BoardPosition.h"
#include "MoveHistory.h"
#include "../../data/inc/GameSaver.h"
#include "../../data/inc/GameLoader.h"
#include "../../test/inc/UnitTest.h"

#ifndef FACADE_H_
#define FACADE_H_

class Facade {
public:
	Facade();
	~Facade();
	void NewGame();
	std::unordered_set<BoardPosition> GetValidMoves(const BoardPosition &);
	bool CheckForCheck(int) const;
	bool WillKingBeInCheck(const BoardPosition &, std::unordered_set<BoardPosition> &);
	bool CheckForCheckmate(const int);
	Piece * MovePiece(const BoardPosition &, const BoardPosition &);
	Move UndoLastMove();
	void SwitchTurns();
	void SaveGameAs(const std::string &);
	bool SaveGame() const;
	bool LoadGame(const std::string &) const;
	bool Checkmate() const;
	bool Stalemate() const;
	bool AnyMovesMadeYet() const;
	int WhoseTurnIsIt() const;
	bool ShouldIHighlighThisCell(const BoardPosition &) const;

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
	Board * boardPtr;
	int whoseTurnIsIt;
	MoveHistory * gameHistory;
	GameSaver * gameSaver;
	bool checkmate;
	bool stalemate;

	bool CheckStraight(BoardPosition &, const int) const;
	bool CheckForStraightAttack(const Piece *, const int) const;
	bool CheckDiagonal(BoardPosition &, const int) const;
	bool CheckForDiagonalAttack(const Piece *, const int) const;
	bool CheckKnightPositions(BoardPosition &, const int) const;
	bool CheckKingPositions(BoardPosition &, const int) const;
};

#endif /* FACADE_H_ */
