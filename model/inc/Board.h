/*
 * Board.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>

#include "Piece.h"
#include "BoardPosition.h"

class Board {
public:
	Board();
	~Board();
	void Reset();
	Piece * GetPiece(const BoardPosition &) const;
	void ClearCell(const BoardPosition &);
	Piece * SetPiece(const BoardPosition &, const int, const int);
	void SetPiece(const BoardPosition &, Piece *);
	void DeletePiece(const BoardPosition &);

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
//	std::vector< std::vector <Piece> > boardArray;
//	Piece * (* boardArray)[8];
	Piece *** boardArray;
};

#endif /* BOARD_H_ */
