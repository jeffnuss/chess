/*
 * HumanPlayer.h
 *
 *  Created on: Apr 10, 2012
 *      Author: jnuss
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_

#include "IChessPlayer.h"
#include "../../model/inc/Facade.h"

class ChessController;

class HumanPlayer : public IChessPlayer
{
public:
	HumanPlayer(int, Facade *, ChessController *);
	virtual ~HumanPlayer();
	void on_CellSelected(int row, int col, int button);
	void on_TimerEvent();
	int GetColor() const;

private:
	Facade * facadePtr;
	ChessController * controllerPtr;
	int color;
};

#endif /* HUMANPLAYER_H_ */
