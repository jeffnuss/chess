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
				outputFile << "\t\t" << "<piece type = \""
						<< GetPieceTypeString(pieceToPrint->GetType())
						<< "\" color = \"" << GetPieceColorString(pieceToPrint->GetColor())
						<< "\" column = \"" << j
						<< "\" row = \"" << i
						<< "\"/>" << endl;
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

string GameSaver::PiecePrinter(ofstream & outputFile, const Piece * pieceToPrint, const int row, const int col) const
{

}

void GameSaver::OutputHistory(const MoveHistory * gameHistory, ofstream & outputFile) const
{
	deque<Move>::iterator iter = gameHistory->GetFrontIterator();
	deque<Move>::iterator endIter = gameHistory->GetBackIterator();

	while (iter != gameHistory)
	{
		outputFile << "\t\t" << "<move>" << endl;
		outputFile << "\t\t\t" << ""
		iter++;
	}
}

