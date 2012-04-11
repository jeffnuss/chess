/*
 * Bishop.h
 *
 *  Created on: Apr 5, 2012
 *      Author: jnuss
 */

#ifndef BISHOP_H_
#define BISHOP_H_

#include "Piece.h"
#include "Board.h"

class Bishop : public Piece
{
public:
	Bishop(const int);
	std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &, const Board *) const;

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif
};

#endif /* BISHOP_H_ */
