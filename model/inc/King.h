/*
 * King.h
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#ifndef KING_H_
#define KING_H_

#include "Piece.h"
#include "Board.h"

class King :public Piece
{
public:
	King(const int);
	std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &,
			const Board *) const;

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif
};

#endif /* KING_H_ */
