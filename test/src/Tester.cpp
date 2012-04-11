/*
 * Tester.cpp
 *
 *  Created on: Mar 29, 2012
 *      Author: jnuss
 */

#include "Board.h"
#include "BoardPosition.h"
#include "Facade.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

using namespace std;

int main()
{
	bool success = true;

	if (!Board::Test(cout)) success = false;
	if (!BoardPosition::Test(cout)) success = false;
	if (!Facade::Test(cout)) success = false;
	if (!Pawn::Test(cout)) success = false;
	if (!Knight::Test(cout)) success = false;
	if (!Bishop::Test(cout)) success = false;
	if (!Rook::Test(cout)) success = false;
	if (!Queen::Test(cout)) success = false;
	if (!King::Test(cout)) success = false;

	if (success) {
		cout << "Tests Succeeded!" << endl;
	}
	else {
		cout << "Tests Failed!" << endl;
	}

	return 0;
}
