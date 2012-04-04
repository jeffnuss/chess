/*
 * Pawn.h
 *
 *  Created on: Apr 2, 2012
 *      Author: jnuss
 */

#include <unordered_set>

#include "Piece.h"
#include "BoardPosition.h"
#include "Board.h"

#ifndef PAWN_H_
#define PAWN_H_

class Pawn : public Piece
{
public:
	Pawn(int, int);
	~Pawn();
	bool operator==(const Pawn &) const;
	std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &, const Board *) const;
	void CheckForCheck(Board *);
	void CheckForCheckMate(Board *);
};

#endif /* PAWN_H_ */
