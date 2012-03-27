/*
 * Facade.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#include "../inc/Facade.h"

Facade::Facade() {
	// TODO Auto-generated constructor stub

}

Facade::~Facade() {
	// TODO Auto-generated destructor stub
}

void Facade::NewGame()
{
	boardPtr->Reset();
}

