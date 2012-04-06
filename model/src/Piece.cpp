/*
 * Piece.cpp
 *
 *  Created on: Mar 29, 2012
 *      Author: jnuss
 */

#include "../inc/Piece.h"
#include "Board.h"

using namespace std;

Piece::Piece(int pieceType, int pieceColor) : pieceType(pieceType), pieceColor(pieceColor)
{
	// TODO Auto-generated constructor stub

}

Piece::~Piece()
{
	// TODO Auto-generated destructor stub
}

int Piece::GetType() const
{
	return pieceType;
}

int Piece::GetColor() const
{
	return pieceColor;
}

bool Piece::operator==(const Piece & other) const
{
	return (other.pieceType == this->pieceType && other.pieceColor == this->pieceColor);
}

Piece& Piece::operator =(const Piece & pieceToAssign)
{
	if (this == NULL || this == &pieceToAssign)
	{
		return *this;
	}

	this->pieceColor = pieceToAssign.pieceColor;
	this->pieceType = pieceToAssign.pieceType;
	return *this;
}

unordered_set<BoardPosition> Piece::GetLegalMoves(const BoardPosition &, const Board *) const
{
}
