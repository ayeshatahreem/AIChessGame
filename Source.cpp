#include <iostream>
#include "GroupName.h"
#include "ChessState.h"
#include "ChessMove.h"
using namespace std;

int main()
{
	ChessState game;          //allows player 1 to move
	game.showState();
	ChessMove PlayerMove;

	playerGROUP_NAME player(1);
	int totalMoves = game.makeValidMovesList();
	cout <<endl<< "Total Moves: " << totalMoves << endl;
	//player.decideMoveUsingMINIMAX(game, PlayerMove, 3);
	game.makeMove(PlayerMove);
	game.showState();
	int m= player.evaluateState();
	//int m = game.getKnightMoves();
	cout << m;

	system("pause");
	return 0;
}
