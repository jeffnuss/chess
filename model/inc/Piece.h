/*
 * Piece.h
 *
 *  Created on: Mar 29, 2012
 *      Author: jnuss
 */

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
		WHITE, BLACK
	};

	Piece();
	Piece(int, int);
	virtual ~Piece();
	virtual int GetType();
	virtual int GetColor();
	bool operator==(const Piece &) const;
	Piece & operator=(const Piece &);

private:
	int pieceType;
	int pieceColor;
};

#endif /* PIECE_H_ */
