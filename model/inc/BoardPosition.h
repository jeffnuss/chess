/*
 * BoardPosition.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include <iostream>

#ifndef BOARDPOSITION_H_
#define BOARDPOSITION_H_

class BoardPosition {
public:
	BoardPosition();
	BoardPosition(int, int);
	BoardPosition(const BoardPosition &);
	~BoardPosition();
	int GetRow() const;
	int GetCol() const;
	bool operator==(const BoardPosition &) const;
	bool MoveUp();
	bool MoveDown();

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
	int row;
	int col;
};

#endif /* BOARDPOSITION_H_ */
