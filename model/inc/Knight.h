/*
 * Knight.h
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#ifndef KNIGHT_H_
#define KNIGHT_H_

#include "Piece.h"
#include "Board.h"

class Knight : public Piece
{
public:
	Knight(const int);
	std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &,
			const Board *) const;
};

#endif /* KNIGHT_H_ */
