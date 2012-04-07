/*
 * Piece.cpp
 *
 *  Created on: Mar 29, 2012
 *      Author: jnuss
 */

#include "../inc/Piece.h"
#include "Board.h"

using namespace std;

Piece::Piece(const int pieceType, const int pieceColor) : pieceType(pieceType), pieceColor(pieceColor)
{
}

Piece::~Piece()
{
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

bool Piece::ContinuousCheck(const BoardPosition & tempPos,
		const Board * currentBoardPtr,
		unordered_set<BoardPosition> & legalMoves) const
{
	bool keepChecking = true;
	Piece * tempCell = currentBoardPtr->GetPiece(tempPos);
	if (tempCell == NULL)
	{
		legalMoves.insert(tempPos);
	}
	else
	{
		if (tempCell->GetColor() != this->pieceColor)
		{
			legalMoves.insert(tempPos);
		}
		keepChecking = false;
	}
	return keepChecking;
}

void Piece::CheckCell(const BoardPosition & tempPos,
		const Board * currentBoardPtr,
		unordered_set<BoardPosition> & legalMoves) const
{
	Piece * tempCell = currentBoardPtr->GetPiece(tempPos);
	if (tempCell == NULL
			|| tempCell->GetColor() != this->pieceColor)
	{
		legalMoves.insert(tempPos);
	}
}
