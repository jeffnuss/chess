/*
 * ComputerPlayer.h
 *
 *  Created on: Apr 10, 2012
 *      Author: jnuss
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "IChessPlayer.h"
#include "../../model/inc/Facade.h"
#include "ChessController.h"

class ComputerPlayer : public IChessPlayer
{
public:
	ComputerPlayer(int, Facade *, ChessController *);
	virtual ~ComputerPlayer();
	void on_CellSelected(int row, int col, int button);
	void on_TimerEvent();
	int GetColor() const;

private:
	Facade * facadePtr;
	ChessController * controllerPtr;
	int color;
};

#endif /* COMPUTERPLAYER_H_ */
