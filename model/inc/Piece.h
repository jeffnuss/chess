/*
 * Piece.h
 *
 *  Created on: Mar 29, 2012
 *      Author: jnuss
 */

#include <unordered_set>

#include "BoardPosition.h"

class Board;

#ifndef PIECE_H_
#define PIECE_H_

class Piece
{
public:

	enum PieceType
	{
		PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING
	};

	enum PieceColor
	{
		BLACK, WHITE
	};

	Piece(const int, const int);
	virtual ~Piece();
	virtual int GetType() const;
	virtual int GetColor() const;
	virtual std::unordered_set<BoardPosition> GetLegalMoves(const BoardPosition &, const Board *) const;
	bool operator==(const Piece &) const;
	Piece & operator=(const Piece &);	

protected:
	int pieceType;
	int pieceColor;
};

#endif /* PIECE_H_ */
