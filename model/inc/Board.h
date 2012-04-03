/*
 * Board.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <vector>
#include <iostream>

#include "Piece.h"

#ifndef BOARD_H_
#define BOARD_H_

class Board {
public:
	Board();
	~Board();
	void Reset();
	static bool Test(std::ostream &);

private:
//	std::vector< std::vector <Piece> > boardArray;
	Piece * (* boardArray)[8];
};

#endif /* BOARD_H_ */
