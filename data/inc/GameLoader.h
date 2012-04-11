/*
 * GameLoader.h
 *
 *  Created on: Apr 10, 2012
 *      Author: jnuss
 */

#ifndef GAMELOADER_H_
#define GAMELOADER_H_

#include "../../model/inc/MoveHistory.h"
#include "../../model/inc/Board.h"
#include  "URLInputStream.h"
#include "HTMLTokenizer.h"

class GameLoader {
public:
	GameLoader();
	~GameLoader();
	void LoadGame(const std::string &, Board *, MoveHistory *) const;
	void LoadBoard(HTMLTokenizer &, Board *) const;
	void LoadMoveHistory(HTMLTokenizer &, MoveHistory *) const;

private:
	int ConvertTypeStrToInt(const std::string &) const;
	int ConvertColorStrToInt(const std::string &) const;
	void CheckForEndToken(const HTMLToken &) const;

};

#endif /* GAMELOADER_H_ */
