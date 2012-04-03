/*
 * Tester.cpp
 *
 *  Created on: Mar 29, 2012
 *      Author: jnuss
 */

#include "Board.h"

using namespace std;

int main()
{
	bool success = true;

	if (!Board::Test(cout)) success = false;

	if (success) {
		cout << "Tests Succeeded!" << endl;
	}
	else {
		cout << "Tests Failed!" << endl;
	}

	return 0;
}
