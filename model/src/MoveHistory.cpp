/*
 * MoveHistory.cpp
 *
 *  Created on: Apr 9, 2012
 *      Author: jnuss
 */

#include "../inc/MoveHistory.h"

using namespace std;

MoveHistory::MoveHistory()
{
}

void MoveHistory::AddMove(const Move & moveToAdd)
{
	moveHistory.push_front(moveToAdd);
}

Move & MoveHistory::GetLastMove()
{
	return moveHistory.front();
}

Move MoveHistory::DeleteLastMove()
{
	Move tempMove(moveHistory.front());
	moveHistory.pop_front();
	return tempMove;
}

void MoveHistory::Clear()
{
	moveHistory.clear();
}

deque<Move>::const_reverse_iterator MoveHistory::GetReverseFrontIterator() const
{
	return moveHistory.rbegin();
}

deque<Move>::const_reverse_iterator MoveHistory::GetReverseBackIterator() const
{
	return moveHistory.rend();
}

bool MoveHistory::IsEmpty() const
{
	return moveHistory.empty();
}


