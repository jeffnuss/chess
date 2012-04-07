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
	BoardPosition GetBlackKingPostion() const;
	BoardPosition GetWhiteKingPostion() const;

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
	BoardPosition blackKingPosition;
	BoardPosition whiteKingPosition;
	Piece *** boardArray;
};

#endif /* BOARD_H_ */
