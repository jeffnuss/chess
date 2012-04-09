/*
 * Move.cpp
 *
 *  Created on: Apr 9, 2012
 *      Author: jnuss
 */

#include "../inc/Move.h"

Move::Move()
{
}

Move::Move(const Piece * movedPiece, const BoardPosition & moveFrom,
		const BoardPosition & moveTo)
		: pieceType(movedPiece->GetType()),
		  pieceColor(movedPiece->GetColor()),
		  moveFrom(moveFrom),
		  moveTo(moveTo),
		  capturedPieceType(-1),
		  caputuredPiecePosition(BoardPosition(-1, -1))
{
}

Move::Move(const Piece * movedPiece, const BoardPosition & moveFrom,
		const BoardPosition & moveTo, const Piece * capturedPiece,
		const BoardPosition & caputuredPiecePosition)
		: pieceType(movedPiece->GetType()),
		  pieceColor(movedPiece->GetColor()),
		  moveFrom(moveFrom),
		  moveTo(moveTo),
		  capturedPieceType(capturedPiece->GetType()),
		  caputuredPiecePosition(caputuredPiecePosition)
{
}

