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
#include "../../test/inc/UnitTest.h"

#ifndef FACADE_H_
#define FACADE_H_

class Facade {
public:
	Facade();
	~Facade();
	void NewGame();
	std::unordered_set<BoardPosition> GetValidMoves(const BoardPosition &) const;
	bool CheckForCheck(const std::unordered_set<BoardPosition> &) const;
	bool CheckForCheckMate(const std::unordered_set<BoardPosition> &) const;
	Piece * MovePiece(const BoardPosition &, const BoardPosition &);

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
	Board * boardPtr;
};

#endif /* FACADE_H_ */
