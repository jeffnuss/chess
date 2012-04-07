/*
 * BoardPosition.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include "../inc/BoardPosition.h"
#include "../../test/inc/UnitTest.h"

using namespace std;

BoardPosition::BoardPosition()
{
	// TODO Auto-generated constructor stub

}

BoardPosition::BoardPosition(int row, int col) : row(row), col(col)
{
}

BoardPosition::BoardPosition(const BoardPosition & other)
{
	this->row = other.row;
	this->col = other.col;
}

BoardPosition::~BoardPosition()
{
	// TODO Auto-generated destructor stub
}

int BoardPosition::GetRow() const
{
	return row;
}

int BoardPosition::GetCol() const
{
	return col;
}

bool BoardPosition::MoveUp()
{
	if (row > 0)
	{
		row--;
		return true;
	}

	return false;
}

bool BoardPosition::MoveDown()
{
	if (row < 7)
	{
		row++;
		return true;
	}

	return false;
}

bool BoardPosition::MoveRight()
{
	if (col < 7)
	{
		col++;
		return true;
	}

	return false;
}

bool BoardPosition::MoveLeft()
{
	if (col > 0)
	{
		col--;
		return true;
	}

	return false;
}

bool BoardPosition::MoveDownLeft()
{
	if (row < 7 && col > 0)
	{
		row++;
		col--;
		return true;
	}

	return false;
}

bool BoardPosition::MoveDownRight()
{
	if (row < 7 && col < 7)
	{
		row++;
		col++;
		return true;
	}

	return false;
}

bool BoardPosition::MoveUpLeft()
{
	if (row > 0 && col > 0)
	{
		row--;
		col--;
		return true;
	}

	return false;
}

bool BoardPosition::MoveUpRight()
{
	if (row > 0 && col < 7)
	{
		row--;
		col++;
		return true;
	}

	return false;
}

bool BoardPosition::operator==(const BoardPosition & other) const
{
	return (this->col == other.col && this->row == other.row);
}

bool BoardPosition::operator!=(const BoardPosition & other) const
{
	return (this->col != other.col || this->row != other.row);
}

#ifndef NDEBUG
bool BoardPosition::Test(std::ostream & os)
{
	bool success = true;

	BoardPosition testBP(2, 3);

	TEST(testBP.col == testBP.GetCol());
	TEST(testBP.row == testBP.GetRow());

	testBP.MoveDown();
	TEST(testBP.GetRow() == 3);

	testBP.MoveDown();
	TEST(testBP.GetRow() == 4);

	testBP.MoveUp();
	TEST(testBP.GetRow() == 3);

	testBP.MoveUp();
	TEST(testBP.GetRow() == 2);

	testBP.MoveLeft();
	TEST(testBP.GetCol() == 2);

	testBP.MoveRight();
	TEST(testBP.GetCol() == 3);

	testBP.MoveDownLeft();
	TEST(testBP.GetRow() == 3);
	TEST(testBP.GetCol() == 2);

	testBP.MoveUpRight();
	TEST(testBP.GetRow() == 2);
	TEST(testBP.GetCol() == 3);

	testBP.MoveDownRight();
	TEST(testBP.GetRow() == 3);
	TEST(testBP.GetCol() == 4);

	testBP.MoveUpLeft();
	TEST(testBP.GetRow() == 2);
	TEST(testBP.GetCol() == 3);

	TEST(testBP == BoardPosition(2, 3));

	return success;
}

#endif
