/*
 * MoveHistory.h
 *
 *  Created on: Apr 9, 2012
 *      Author: jnuss
 */

#ifndef MOVEHISTORY_H_
#define MOVEHISTORY_H_

#include <deque>

#include "Move.h"

class MoveHistory {
public:
	MoveHistory();
	void AddMove(const Move &);
	Move & GetLastMove();
	Move & GetFirstMove();
	Move DeleteLastMove();
	void Clear();
	const std::deque<Move>::iterator GetFrontIterator() const;
	const std::deque<Move>::iterator GetBackIterator() const;

private:
	std::deque<Move> moveHistory;
};

#endif /* MOVEHISTORY_H_ */
