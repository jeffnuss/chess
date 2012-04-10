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
	std::deque<Move>::const_reverse_iterator GetReverseFrontIterator() const;
	std::deque<Move>::const_reverse_iterator GetReverseBackIterator() const;
	bool IsEmpty() const;
	int WhoMadeTheLastMove() const;

private:
	std::deque<Move> moveHistory;
};

#endif /* MOVEHISTORY_H_ */
