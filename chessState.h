#ifndef ChessState_H
#define ChessState_H

#include <iostream>
#include <vector>

#include "ChessMove.h"

using namespace std;

class ChessState
{
private:
	void showPiece(int pieceCode);
public:
	//attributes
	ChessMove Moves[200];
	vector <ChessState*> myStates;
	int playerToMove;
	int board[8][8];

	//functions
	int makeValidMovesList();
	ChessState();
	void showState();
	void Pawn(int i, int j);
	void Bishop(int i, int j);
	void Rook(int i, int j);
	void Queen(int i, int j);
	void King(int i, int j);
	void Knight(int i, int j);

	int moveUp_Queen(int i, int j);
	int moveDown_Queen(int i, int j);
	int moveLeft_Queen(int i, int j);
	int moveRight_Queen(int i, int j);
	int UpperLeftMove_Queen(int i, int j);
	int UpperRightMove_Queen(int i, int j);
	int DownRightMove_Queen(int i, int j);
	int DownLeftMove_Queen(int i, int j);

	int moveUp_Rook(int i, int j);
	int moveDown_Rook(int i, int j);
	int moveLeft_Rook(int i, int j);
	int moveRight_Rook(int i, int j);

	int UpperLeftMove_Bishop(int i, int j);
	int UpperRightMove_Bishop(int i, int j);
	int DownLeftMove_Bishop(int i, int j);
	int DownRightMove_Bishop(int i, int j);

	bool PawnCheckForInitial(int i, int j);
	bool BishopCheckForInitial(int i, int j);
	bool PawnAttackingPair(int i, int j);

	int King_Up(int i, int j);
	int King_Down(int i, int j);
	int King_Left(int i, int j);
	int King_Right(int i, int j);
	int King_UpLeftCorner(int i, int j);
	int King_UpRightCorner(int i, int j);
	int King_DownLeftCorner(int i, int j);
	int King_DownRightCorner(int i, int j);

	//Check
	void kingIncheck(int pieceCode);
	void pieceSafe(int i, int j);

	bool makeMove(ChessMove pieceMove);
	bool checkIfLegalToMove(int, int, int, int, int);

	int getPawnMoves();
	int getBishopMoves();
	int getQueenMoves();
	int getRookMoves();
	int getKingMoves();
	int getKnightMoves();
};

#endif

