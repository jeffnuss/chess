/*
 * Pawn.h
 *
 *  Created on: Apr 2, 2012
 *      Author: jnuss
 */

#include "Piece.h"

#ifndef PAWN_H_
#define PAWN_H_

class Pawn : public Piece
{
public:
	Pawn(int, int);
	~Pawn();
	bool operator==(const Pawn &) const;
};

#endif /* PAWN_H_ */
