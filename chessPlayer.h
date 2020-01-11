#ifndef PLAYER_H
#define PLAYER_H

#include "chessMove.h"
#include "chessState.h"

#include <string>
#include <vector>
#include <iostream>
class chessPlayer
{
private:
	virtual int evaluateState() { return 1; };
public:
	chessPlayer(int playerColor = 1);
	int playerColor;
	// string playerName;
	virtual int decideMoveUsingMINIMAX(ChessState &gameState, ChessMove &returnMove, unsigned int depth = 1) = 0;
	void gameResult(int winner);
};

#endif // PLAYER_H
