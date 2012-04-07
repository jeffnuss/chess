/*
 * Queen.h
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#ifndef QUEEN_H_
#define QUEEN_H_

#include "Piece.h"
#include "Board.h"

class Queen : public Piece
{
public:
	Queen(const int);
	std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &, const Board *) const;
};

#endif /* QUEEN_H_ */
