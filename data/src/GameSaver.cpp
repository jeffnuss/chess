/*
 * GameSaver.cpp
 *
 *  Created on: Apr 9, 2012
 *      Author: jnuss
 */

#include <fstream>

#include "../inc/GameSaver.h"

using namespace std;

GameSaver::GameSaver(const string & fileName) : fileName(fileName)
{
}
GameSaver::~GameSaver()
{
}

void GameSaver::SaveGameAs(const string & newFileName, const Board * boardPtr,
		const MoveHistory * gameHistory)
{
	fileName = newFileName;
	SaveGame(boardPtr, gameHistory);
}

void GameSaver::SaveGame(const Board * boardPtr, const MoveHistory * gameHistory) const
{
	ofstream outputFile;
	outputFile.open(fileName.c_str());

	outputFile << "<chessgame>" << endl;

	outputFile << "\t" << "<board>" << endl;
	OutputBoard(boardPtr, outputFile);
	outputFile << "\t" << "</board>" << endl;

	outputFile << "\t" << "<history>" << endl;
	OutputHistory(gameHistory, outputFile);
	outputFile << "\t" << "</history>" << endl;

	outputFile << "</chessgame>" << endl;

	outputFile.close();
}

void GameSaver::OutputBoard(const Board * boardPtr, ofstream & outputFile) const
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Piece * pieceToPrint = boardPtr->GetPiece(BoardPosition(i, j));
			if (pieceToPrint != NULL)
			{
				outputFile << "\t\t";
				PiecePrinter(outputFile, pieceToPrint, i, j);
			}
		}
	}
}

string GameSaver::GetPieceTypeString(const int pieceType) const
{
	switch (pieceType)
	{
	case Piece::PAWN:
		return "pawn";
		break;
	case Piece::KNIGHT:
		return "knight";
		break;
	case Piece::BISHOP:
		return "bishop";
		break;
	case Piece::ROOK:
		return "rook";
		break;
	case Piece::QUEEN:
		return "queen";
		break;
	case Piece::KING:
		return "king";
		break;
	}
}

string GameSaver::GetPieceColorString(const int pieceColor) const
{
	switch (pieceColor)
	{
	case Piece::BLACK:
		return "black";
		break;
	case Piece::WHITE:
		return "white";
		break;
	}
}

void GameSaver::PiecePrinter(ofstream & outputFile, const Piece * pieceToPrint, const int row, const int col) const
{
	outputFile << "<piece type = \""
			<< GetPieceTypeString(pieceToPrint->GetType())
			<< "\" color = \"" << GetPieceColorString(pieceToPrint->GetColor())
			<< "\" column = \"" << col
			<< "\" row = \"" << row
			<< "\"/>" << endl;
}

void GameSaver::PiecePrinter(ofstream & outputFile, const int pieceType, const int pieceColor, const int row, const int col) const
{
	outputFile << "<piece type = \""
			<< GetPieceTypeString(pieceType)
			<< "\" color = \"" << GetPieceColorString(pieceColor)
			<< "\" column = \"" << col
			<< "\" row = \"" << row
			<< "\"/>" << endl;
}

void GameSaver::OutputHistory(const MoveHistory * gameHistory, ofstream & outputFile) const
{
	// Iterate in reverse order
	deque<Move>::const_reverse_iterator startIter = gameHistory->GetReverseFrontIterator();
	deque<Move>::const_reverse_iterator endIter = gameHistory->GetReverseBackIterator();

	while (startIter != endIter)
	{
		outputFile << "\t\t" << "<move>" << endl;
		outputFile << "\t\t\t";
		PiecePrinter(outputFile, startIter->GetPieceType(), startIter->GetPieceColor(),
				startIter->GetOriginPosition().GetRow(), startIter->GetOriginPosition().GetCol());
		PiecePrinter(outputFile, startIter->GetPieceType(), startIter->GetPieceColor(),
				startIter->GetDestinationPosition().GetRow(), startIter->GetDestinationPosition().GetCol());
		if (startIter->GetCapturedPieceType() != -1)
		{
			PiecePrinter(outputFile, startIter->GetCapturedPieceType(), startIter->GetCapturedPieceColor(),
					startIter->GetCapturedPiecePosition().GetRow(), startIter->GetCapturedPiecePosition().GetCol());
		}
		outputFile << "\t\t" << "</move>" << endl;
		startIter++;
	}
}

