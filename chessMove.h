#ifndef MOVE_H
#define MOVE_H

class ChessMove
{
public:
	ChessMove();
	ChessMove(int, int, int, int);
	unsigned int From[2];
	unsigned int To[2];
};

#endif // MOVE_H
