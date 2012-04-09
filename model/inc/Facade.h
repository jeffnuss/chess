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
#include "../../test/inc/UnitTest.h"

#ifndef FACADE_H_
#define FACADE_H_

class Facade {
public:
	Facade();
	~Facade();
	void NewGame();
	std::unordered_set<BoardPosition> GetValidMoves(const BoardPosition &) const;
	bool CheckForCheck() const;
	bool WillKingBeInCheck(const std::unordered_set<BoardPosition> &) const;
	bool CheckForCheckMate(const std::unordered_set<BoardPosition> &) const;
	Piece * MovePiece(const BoardPosition &, const BoardPosition &);
	Move UndoLastMove();
	void SwitchTurns();
	void SaveGameAs(const std::string &);
	void SameGame() const;

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
	Board * boardPtr;
	int whoseTurnIsIt;
	MoveHistory * gameHistory;
	GameSaver * gameSaver;

	bool CheckStraight(BoardPosition &) const;
	bool CheckForStraightAttack(const Piece *) const;
	bool CheckDiagonal(BoardPosition &) const;
	bool CheckForDiagonalAttack(const Piece *) const;
	bool CheckKnightPositions(BoardPosition &) const;
};

#endif /* FACADE_H_ */
