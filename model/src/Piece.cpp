/*
 * Piece.cpp
 *
 *  Created on: Mar 29, 2012
 *      Author: jnuss
 */

#include "../inc/Piece.h"

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
