/*
 * GameLoader.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: jnuss
 */

#include "../inc/GameLoader.h"
#include "../inc/CS240Exception.h"
#include "../inc/URLInputStream.h"
#include "../inc/HTMLToken.h"
#include "../inc/HTMLTokenizer.h"


using namespace std;

GameLoader::GameLoader() {
	// TODO Auto-generated constructor stub

}

GameLoader::~GameLoader() {
	// TODO Auto-generated destructor stub
}

void GameLoader::LoadGame(const string & filePath, Board * boardPtr, MoveHistory * gameHistory) const
{
	try
	{
		string prefix = "file://";
		string urlToLoad = prefix + filePath;
		URLInputStream * stream = new URLInputStream(urlToLoad);
		HTMLTokenizer tokenizer(stream);
		LoadBoard(tokenizer, boardPtr);
		LoadMoveHistory(tokenizer, gameHistory);
		delete stream;
	}
    catch (exception &e)
    {
        cout << "Exception Occurred:" << e.what() << endl;
    }
    catch (CS240Exception &e)
    {
        cout << "Exception Occurred:" << e.GetMessage() << endl;
    }
	catch (...)
	{

	}
}

void GameLoader::LoadBoard(HTMLTokenizer & tokenizer, Board * boardPtr) const
{
	HTMLToken currentToken = tokenizer.GetNextToken();
	while (currentToken.GetValue() != "board")
	{
		CheckForEndToken(currentToken);
		currentToken = tokenizer.GetNextToken();
	}

	currentToken = tokenizer.GetNextToken();
	while (currentToken.GetValue() != "board")
	{
		CheckForEndToken(currentToken);
		if (currentToken.GetValue() == "piece")
		{
			int pieceType = ConvertTypeStrToInt(currentToken.GetAttribute("type"));
			int pieceColor = ConvertColorStrToInt(currentToken.GetAttribute("color"));
			int col = atoi(currentToken.GetAttribute("column").c_str());
			int row = atoi(currentToken.GetAttribute("row").c_str());
			boardPtr->SetPiece(BoardPosition(row, col), pieceType, pieceColor);
		}
		currentToken = tokenizer.GetNextToken();
	}
}

void GameLoader::LoadMoveHistory(HTMLTokenizer & tokenizer, MoveHistory * gameHistory) const
{
	HTMLToken currentToken = tokenizer.GetNextToken();
	while (currentToken.GetValue() != "history")
	{
		CheckForEndToken(currentToken);
		currentToken = tokenizer.GetNextToken();
	}

	currentToken = tokenizer.GetNextToken();
	while (currentToken.GetValue() != "history")
	{
		CheckForEndToken(currentToken);
		if (currentToken.GetValue() == "move"
				&& currentToken.GetType() == HTMLTokenType::TAG_START)
		{
			while (currentToken.GetValue() != "piece")
			{
				CheckForEndToken(currentToken);
				currentToken = tokenizer.GetNextToken();
			}
			HTMLToken origin = currentToken;

			currentToken = tokenizer.GetNextToken();
			while (currentToken.GetValue() != "piece")
			{
				CheckForEndToken(currentToken);
				currentToken = tokenizer.GetNextToken();
			}
			HTMLToken destination = currentToken;

			currentToken = tokenizer.GetNextToken();

			int originPieceType = ConvertTypeStrToInt(origin.GetAttribute("type"));
			int originPieceColor = ConvertColorStrToInt(origin.GetAttribute("color"));
			int originCol = atoi(origin.GetAttribute("column").c_str());
			int originRow = atoi(origin.GetAttribute("row").c_str());
			int destinationCol = atoi(destination.GetAttribute("column").c_str());
			int destinationRow = atoi(destination.GetAttribute("row").c_str());
			int capturedPieceType = -1;
			int capturedCol = -1;
			int capturedRow = -1;

			while (currentToken.GetValue() != "piece"
					&& currentToken.GetValue() != "move")
			{
				CheckForEndToken(currentToken);
				currentToken = tokenizer.GetNextToken();
			}

			if (currentToken.GetValue() == "piece")
			{
				capturedPieceType = ConvertTypeStrToInt(currentToken.GetAttribute("type"));
				capturedCol = atoi(currentToken.GetAttribute("column").c_str());
				capturedRow = atoi(currentToken.GetAttribute("row").c_str());
			}

			gameHistory->AddMove(Move(originPieceType,
					originPieceColor, BoardPosition(originRow, originCol),
					BoardPosition(destinationRow, destinationCol),
					capturedPieceType, BoardPosition(capturedRow, capturedCol)));
		}
		else
		{
			currentToken = tokenizer.GetNextToken();
		}
	}
}

void GameLoader::CheckForEndToken(const HTMLToken & tokenToCheck) const
{
	if (tokenToCheck.GetType() == HTMLTokenType::END)
	{
		throw CS240Exception("Invalid file");
	}
}

int GameLoader::ConvertTypeStrToInt(const string & stringToConvert) const
{
	int pieceType = -1;
	if (stringToConvert == "pawn")
	{
		pieceType = Piece::PAWN;
	}
	else if (stringToConvert == "knight")
	{
		pieceType = Piece::KNIGHT;
	}
	else if (stringToConvert == "bishop")
	{
		pieceType = Piece::BISHOP;
	}
	else if (stringToConvert == "rook")
	{
		pieceType = Piece::ROOK;
	}
	else if (stringToConvert == "queen")
	{
		pieceType = Piece::QUEEN;
	}
	else
	{
		pieceType = Piece::KING;
	}

	return pieceType;
}

int GameLoader::ConvertColorStrToInt(const string & stringToConvert) const
{
	int pieceColor = -1;

	if (stringToConvert == "black")
	{
		pieceColor = Piece::BLACK;
	}

	else
	{
		pieceColor = Piece::WHITE;
	}

	return pieceColor;
}
