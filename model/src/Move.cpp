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

Move::Move(const Move & other)
	: pieceType(other.pieceType),
	  pieceColor(other.pieceColor),
	  moveFrom(other.moveFrom),
	  moveTo(other.moveTo),
	  capturedPieceType(other.capturedPieceType),
	  caputuredPiecePosition(other.caputuredPiecePosition)
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

Move::Move(const int movedPieceType, const int movedPieceColor, const BoardPosition & moveFrom,
		const BoardPosition & moveTo, const int capturedPieceType,
		const BoardPosition & caputuredPiecePosition)
		: pieceType(movedPieceType),
		  pieceColor(movedPieceColor),
		  moveFrom(moveFrom),
		  moveTo(moveTo),
		  capturedPieceType(capturedPieceType),
		  caputuredPiecePosition(caputuredPiecePosition)
{
}

int Move::GetPieceType() const
{
	return pieceType;
}

int Move::GetPieceColor() const
{
	return pieceColor;
}

BoardPosition Move::GetOriginPosition() const
{
	return moveFrom;
}

BoardPosition Move::GetDestinationPosition() const
{
	return moveTo;
}

int Move::GetCapturedPieceType() const
{
	return capturedPieceType;
}

int Move::GetCapturedPieceColor() const
{
	return (pieceColor == Piece::BLACK ? Piece::WHITE : Piece::BLACK);
}

BoardPosition Move::GetCapturedPiecePosition() const
{
	return caputuredPiecePosition;
}
