/*
 * Facade.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include "Board.h"

#ifndef FACADE_H_
#define FACADE_H_

class Facade {
public:
	Facade();
	~Facade();
	void NewGame();

private:
	Board * boardPtr;
};

#endif /* FACADE_H_ */
