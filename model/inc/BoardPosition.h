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
	bool MoveUpLeft();
	bool MoveUpRight();
	bool MoveDownLeft();
	bool MoveDownRight();

#ifndef NDEBUG
	static bool Test(std::ostream &);
#endif

private:
	int row;
	int col;

};

namespace std {
  template <> struct hash<BoardPosition>
  {
	size_t operator()(const BoardPosition & bpToHash) const
	{
	  return (hash<int>()((hash<int>()(bpToHash.GetRow()) + hash<int>()(bpToHash.GetCol()))));
	}
  };
}

#endif /* BOARDPOSITION_H_ */
