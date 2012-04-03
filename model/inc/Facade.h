/*
 * Facade.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <set>

#include "Board.h"
#include "BoardPosition.h"

#ifndef FACADE_H_
#define FACADE_H_

class Facade {
public:
	Facade();
	~Facade();
	void NewGame();
	std::set<BoardPosition> getValidMoves(const BoardPosition &) const;

private:
	Board * boardPtr;
};

#endif /* FACADE_H_ */
