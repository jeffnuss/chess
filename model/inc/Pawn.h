/*
 * Pawn.h
 *
 *  Created on: Apr 2, 2012
 *      Author: jnuss
 */

#ifndef PAWN_H_
#define PAWN_H_

#include <iostream>

#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
	Pawn(const int);
	bool operator==(const Pawn &) const;
	std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &, const Board *) const;

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
	bool ThereIsAPieceInMyWay(const BoardPosition &, const Board *) const;
	bool CheckForCaptures(const BoardPosition &, const Board *, std::unordered_set<BoardPosition> &) const;
};

#endif /* PAWN_H_ */
