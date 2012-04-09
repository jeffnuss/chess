/*
 * MoveHistory.cpp
 *
 *  Created on: Apr 9, 2012
 *      Author: jnuss
 */

#include "../inc/MoveHistory.h"

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

const deque<Move>::iterator MoveHistory::GetFrontIterator() const
{
	return moveHistory.begin();
}

const deque<Move>::iterator MoveHistory::GetBackIterator() const
{
	return moveHistory.end();
}
