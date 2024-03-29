/*
 * ChessController.h
 *
 *  Created on: Mar 26, 2012
 *      Author: jnuss
 */

#ifndef CHESSCONTROLLER_H_
#define CHESSCONTROLLER_H_

#include <unordered_set>

#include "IChessController.h"
#include "../../view/inc/IChessView.h"
#include "../../model/inc/Facade.h"
#include "../../model/inc/BoardPosition.h"
#include "HumanPlayer.h"

class ChessController : public IChessController
{
public:
	ChessController(char);
	~ChessController();

	void on_CellSelected(int row, int col, int button);
	void on_DragStart(int row,int col);
	bool on_DragEnd(int row,int col);
	void on_NewGame();
	void on_SaveGame();
	void on_SaveGameAs();
	void on_LoadGame();
	void on_UndoMove();
	void on_QuitGame();
	void on_TimerEvent();
	void SetView(IChessView * view);
	void HighlightMoves(const BoardPosition &);
	void ClearCurrentHighlights();
	void MovePiece(const BoardPosition &, const BoardPosition, const Piece *);
	ImageName GetPieceImage(const int, const int) const;
	void UpdateGameStatus();
	void UpdateTurnDisplay();
	void LoadNewBoard();
	void CellSelected(int, int, int);

private:
	IChessView * viewPtr;
	Facade * facadePtr;
	std::unordered_set<BoardPosition> currentHighlightedCells;
	BoardPosition currentSelectedCell;
	IChessPlayer * whitePlayer;
	IChessPlayer * blackPlayer;

};

#endif /* CHESSCONTROLLER_H_ */
