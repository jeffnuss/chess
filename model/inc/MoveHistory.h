/*
 * MoveHistory.h
 *
 *  Created on: Apr 9, 2012
 *      Author: jnuss
 */

#ifndef MOVEHISTORY_H_
#define MOVEHISTORY_H_

#include <stack>

#include "Move.h"

class MoveHistory {
public:
	MoveHistory();
	void AddMove(const Move &);
	Move & GetLastMove();
	Move DeleteLastMove();
	void Clear();

private:
	std::stack<Move> moveHistory;
};

#endif /* MOVEHISTORY_H_ */
