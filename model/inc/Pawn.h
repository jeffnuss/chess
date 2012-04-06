/*
 * Pawn.h
 *
 *  Created on: Apr 2, 2012
 *      Author: jnuss
 */

#include <unordered_set>
#include <iostream>

#include "Piece.h"
#include "BoardPosition.h"
#include "Board.h"

#ifndef PAWN_H_
#define PAWN_H_

class Pawn : public Piece
{
public:
	Pawn(int);
	~Pawn();
	bool operator==(const Pawn &) const;
	std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &, const Board *) const;
	bool ThereIsAPieceInMyWay(const BoardPosition &, const Board *) const;
	bool CheckForCaptures(const BoardPosition &, const Board *, std::unordered_set<BoardPosition> &) const;

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif
};

#endif /* PAWN_H_ */
