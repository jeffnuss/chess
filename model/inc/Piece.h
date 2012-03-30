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
	Piece();
	Piece(int, int);
	virtual ~Piece();
	virtual int GetType();
	virtual int GetColor();

private:
	int pieceType;
	int pieceColor;
};

#endif /* PIECE_H_ */
