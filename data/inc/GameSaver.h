/*
 * GameSaver.h
 *
 *  Created on: Apr 9, 2012
 *      Author: jnuss
 */

#ifndef GAMESAVER_H_
#define GAMESAVER_H_

#include "../../model/inc/Board.h"
#include "../../model/inc/MoveHistory.h"
#include "../../model/inc/Move.h"

class GameSaver
{
public:
	GameSaver(const std::string &);
	~GameSaver();
	void SaveGameAs(const std::string &, const Board *, const MoveHistory *);
	void SaveGame(const Board *, const MoveHistory *) const;
	void OutputBoard(const Board *, std::ofstream &) const;
	std::string GetPieceTypeString(const int) const;
	std::string GetPieceColorString(const int) const;
	void OutputHistory(const MoveHistory *, std::ofstream &) const;
	void PiecePrinter(std::ofstream &, const Piece *, const int, const int) const;
	void PiecePrinter(std::ofstream &, const int, const int, const int, const int) const;

private:
	std::string fileName;
};

#endif /* GAMESAVER_H_ */
