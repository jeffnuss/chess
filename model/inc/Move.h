/*
 * Move.h
 *
 *  Created on: Apr 9, 2012
 *      Author: jnuss
 */

#ifndef MOVE_H_
#define MOVE_H_

#include "Piece.h"
#include "BoardPosition.h"

class Move
{
public:
	Move();
	Move(const Move &);
	Move(const Piece *, const BoardPosition &, const BoardPosition &);
	Move(const Piece *, const BoardPosition &, const BoardPosition &,
			const Piece *, const BoardPosition &);
	Move(const int, const int, const BoardPosition &, const BoardPosition &,
			const int capturedPieceType, const BoardPosition & caputuredPiecePosition);

	int GetPieceType() const;
	int GetPieceColor() const;
	BoardPosition GetOriginPosition() const;
	BoardPosition GetDestinationPosition() const;
	int GetCapturedPieceType() const;
	int GetCapturedPieceColor() const;
	BoardPosition GetCapturedPiecePosition() const;

private:
	int pieceType;
	int pieceColor;
	BoardPosition moveFrom;
	BoardPosition moveTo;
	int capturedPieceType;
	BoardPosition caputuredPiecePosition;
};

#endif /* MOVE_H_ */
