/*
 * Board.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <iostream>

#include "Piece.h"
#include "BoardPosition.h"

#ifndef BOARD_H_
#define BOARD_H_

class Board {
public:
	Board();
	~Board();
	void Reset();
	Piece * GetPiece(const BoardPosition &) const;
	void ClearCell(const BoardPosition &);
	void SetPiece(const BoardPosition &, Piece *);

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
//	std::vector< std::vector <Piece> > boardArray;
	Piece * (* boardArray)[8];
};

#endif /* BOARD_H_ */
