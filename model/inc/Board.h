/*
 * Board.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <vector>

#ifndef BOARD_H_
#define BOARD_H_

class Board {
public:
	Board();
	~Board();
	void Reset();

private:
	std::vector< std::vector <int> > * boardArray;
};

#endif /* BOARD_H_ */
