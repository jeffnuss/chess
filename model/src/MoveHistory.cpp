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
	moveHistory.push(moveToAdd);
}

Move & MoveHistory::GetLastMove()
{
	return moveHistory.top();
}

Move MoveHistory::DeleteLastMove()
{
	Move tempMove(moveHistory.top());
	moveHistory.pop();
	return tempMove;
}

void MoveHistory::Clear()
{
	while (!moveHistory.empty())
	{
		moveHistory.pop();
	}
}
