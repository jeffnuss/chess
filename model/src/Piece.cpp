/*
 * Piece.cpp
 *
 *  Created on: Mar 29, 2012
 *      Author: jnuss
 */

#include "../inc/Piece.h"
#include "Board.h"

Piece::Piece(int pieceType, int pieceColor) : pieceType(pieceType), pieceColor(pieceColor)
{
	// TODO Auto-generated constructor stub

}

Piece::~Piece()
{
	// TODO Auto-generated destructor stub
}

int Piece::GetType()
{
	return pieceType;
}

int Piece::GetColor()
{
	return pieceColor;
}

bool Piece::operator==(const Piece & other) const
{
	return (other.pieceType == this->pieceType && other.pieceColor == this->pieceColor);
}

Piece& Piece::operator =(const Piece & pieceToAssign)
{
	this->pieceColor = pieceToAssign.pieceColor;
	this->pieceType = pieceToAssign.pieceType;
	return *this;
}
