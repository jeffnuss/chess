/*
 * Rook.h
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#ifndef ROOK_H_
#define ROOK_H_

#include "Piece.h"
#include "Board.h"

class Rook : public Piece
{
public:
	Rook(const int);
	std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &,
			const Board *) const;

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif
};

#endif /* ROOK_H_ */
