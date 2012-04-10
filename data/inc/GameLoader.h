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

class GameLoader {
public:
	GameLoader();
	~GameLoader();
	MoveHistory LoadGame(const std::string &, Board *, MoveHistory *) const;

};

#endif /* GAMELOADER_H_ */
