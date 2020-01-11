#ifndef GROUPNAME_H
#define GROUPNAME_H
#include <string>
#include <vector>
#include <iostream>
#include "chessPlayer.h"

class playerGROUP_NAME : public chessPlayer
{
public:
	int evaluateState();
	void trackBestMoves();
	void doMove(ChessState *newBoard,ChessMove *move);
	playerGROUP_NAME(int playerColor);
	int applyAlphaBetaPruning(ChessState *b, int alpha, int beta, int depth, bool color);
	int decideMoveUsingMINIMAX(ChessState &gameState, ChessMove &returnMove, unsigned int depth = 1);
protected:

private:
};

#endif // GROUPNAME_H
