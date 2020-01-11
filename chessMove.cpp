#include "chessMove.h"

ChessMove::ChessMove()
{
	//ctor
	From[0] = From[1] = 0;
	To[0] = To[1] = 0;
}

ChessMove::ChessMove(int i, int j, int k, int l)
{
	From[0] = i; //0 for row; 1 for col
	From[1] = j;
	To[0] = k;
	To[1] = l;
}
