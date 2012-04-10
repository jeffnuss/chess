/*
 * HumanPlayer.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: jnuss
 */

#include "../inc/HumanPlayer.h"

HumanPlayer::HumanPlayer(int color, Facade * facadePtr, ChessController * controllerPtr)
	: color(color), facadePtr(facadePtr), controllerPtr(controllerPtr)
{
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::on_CellSelected(int row, int col, int button)
{

}

void HumanPlayer::on_TimerEvent()
{

}
