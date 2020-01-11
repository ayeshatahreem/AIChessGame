#include "ChessState.h"
#include <iostream>
using namespace std;

int pawn_left = 0;
int pawn_right = 0;
int pawn_possible_moves = 0;
int bishop_possible_moves = 0;
int queen_possible_moves = 0;
int rook_possible_moves = 0;
int king_possible_moves = 0;
int knight_possible_moves = 0;
bool pawnMiniMax = false;
bool bishopMiniMax = false;
bool queenMiniMax = false;
bool rookMiniMax = false;
bool kingMiniMax = false;
bool knightMiniMax = false;

bool ChessState::checkIfLegalToMove(int piece, int i, int j, int k, int l)
{
	/*if (piece == -1)
	{
		
		int c= Pawn(i, j);
		if (c > 0)
		{
			return true;
		}
	}
	if (piece == -2)
	{
		int c = countKnight(i, j, k, l);
		if (c > 0)
		{
			return true;
		}
	}
	if (piece == -3)
	{
		int c = countBishop(i, j, k, l);
		if (c > 0)
		{
			return true;
		}
	}
	if (piece == -4)
	{
		int c = countRook(i, j, k, l);
		if (c > 0)
		{
			return true;
		}
	}
	if (piece == -5)
	{
		int c = countQueen(i, j, k, l);
		if (c > 0)
		{
			return true;
		}
	}
	if (piece == -6)
	{
		int c = countKing(i, j, k, l);
		if (c > 0)
		{
			return true;
		}
	}*/
	return true;
	//return false;
}
bool ChessState::makeMove(ChessMove pieceMove)
{
	this->playerToMove *= -1;
	return true;
}

int ChessState::getPawnMoves()
{
	return pawn_possible_moves;
}

int ChessState::getBishopMoves()
{
	return bishop_possible_moves;
}

int ChessState::getQueenMoves()
{
	return queen_possible_moves;
}

int ChessState::getRookMoves()
{
	return rook_possible_moves;
}

int ChessState::getKingMoves()
{
	return king_possible_moves;
}

int ChessState::getKnightMoves()
{
	return knight_possible_moves;
}

int ChessState::makeValidMovesList()
{
	if (playerToMove == 1)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == -1)
				{
					Pawn(i, j);
					cout << "Pawn" << endl;
				}
				if (board[i][j] == -2)
				{
					Knight(i, j);
					cout << "Knight" << endl;
				}
				if (board[i][j] == -3)
				{
					Bishop(i, j);
					cout << endl << "Bishop" << endl;
				}
				if (board[i][j] == -4)
				{
					Rook(i, j);
					cout << endl << "Rook" << endl;
				}
				if (board[i][j] == -5)
				{
					Queen(i, j);
					cout << endl << "Queen" << endl;
				}
				if (board[i][j] == -6)
				{
					King(i, j);
					cout << "King" << endl;
				}

			}
		}
	}
	int total_possible_moves = knight_possible_moves + pawn_possible_moves + bishop_possible_moves + king_possible_moves + queen_possible_moves + rook_possible_moves;
	return total_possible_moves;
}

void ChessState::King(int i, int j)
{
	if (i > 0)
	{
		cout << King_Down(i, j);
	}
	if (i < 7)
	{
		cout << King_Up(i, j);
	}
	if (j > 0)
	{
		cout << King_Right(i, j);
	}
	if (j < 7)
	{
		cout << King_Left(i, j);
	}
	if (i > 0 && j > 0)
	{
		cout << King_DownRightCorner(i, j);
	}
	if (i > 0 && j < 7)
	{
		cout << King_DownLeftCorner(i, j);
	}
	if (i < 7 && j > 0)
	{
		cout << King_UpRightCorner(i, j);
	}
	if (i < 7 && j < 7)
	{
		cout << King_UpLeftCorner(i, j);
	}
}

int ChessState::King_Up(int i, int j)
{
	if (board[i + 1][j] >= 0)
	{
		ChessState *C = new ChessState;
		C->board[i + 1][j] = C->board[i][j];
		C->board[i][j] = 0;
		myStates.push_back(C);
		king_possible_moves++;
	}
	return 0;
}

int ChessState::King_Down(int i, int j)
{
	if (board[i - 1][j] >= 0)
	{
		ChessState *C = new ChessState;
		C->board[i - 1][j] = C->board[i][j];
		C->board[i][j] = 0;
		myStates.push_back(C);
		king_possible_moves++;
	}
	return 0;
}

int ChessState::King_Left(int i, int j)
{
	if (board[i][j + 1] >= 0)
	{
		ChessState *C = new ChessState;
		C->board[i][j + 1] = C->board[i][j];
		C->board[i][j] = 0;
		myStates.push_back(C);
		king_possible_moves++;
	}
	return 0;
}

int ChessState::King_Right(int i, int j)
{
	if (board[i][j - 1] >= 0)
	{
		ChessState *C = new ChessState;
		C->board[i][j - 1] = C->board[i][j];
		C->board[i][j] = 0;
		myStates.push_back(C);
		king_possible_moves++;
	}
	return 0;
}

int ChessState::King_UpLeftCorner(int i, int j)
{
	if (board[i + 1][j + 1] >= 0)
	{
		ChessState *C = new ChessState;
		C->board[i + 1][j + 1] = C->board[i][j];
		C->board[i][j] = 0;
		myStates.push_back(C);
		king_possible_moves++;
	}
	return 0;
}

int ChessState::King_UpRightCorner(int i, int j)
{
	if (board[i + 1][j - 1] >= 0)
	{
		ChessState *C = new ChessState;
		C->board[i + 1][j - 1] = C->board[i][j];
		C->board[i][j] = 0;
		myStates.push_back(C);
		king_possible_moves++;
	}
	return 0;
}

int ChessState::King_DownLeftCorner(int i, int j)
{
	if (board[i - 1][j + 1] >= 0)
	{
		ChessState *C = new ChessState;
		C->board[i + 1][j - 1] = C->board[i][j];
		C->board[i][j] = 0;
		myStates.push_back(C);
		king_possible_moves++;
	}
	return 0;
}

int ChessState::King_DownRightCorner(int i, int j)
{
	if (board[i - 1][j - 1] >= 0)
	{
		ChessState *C = new ChessState;
		C->board[i - 1][j - 1] = C->board[i][j];
		C->board[i][j] = 0;
		myStates.push_back(C);
		king_possible_moves++;
	}
	return 0;
}

int ChessState::moveDown_Queen(int i, int j)
{
	int count1 = i;
	while (count1 > 0)
	{
		count1--;
		if (board[count1][j] == 0)
		{
			ChessState *state = new ChessState;
			state->board[count1][j] = state->board[i][j];
			state->board[i][j] = 0;
			myStates.push_back(state);
			queen_possible_moves++;
		}
		else if (board[count1][j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[count1][j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			queen_possible_moves++;
			count1 = 0;
		}
		else
		{
			count1 = 0;
		}
	}
	return queen_possible_moves;
}

int ChessState::moveUp_Queen(int i, int j)
{
	int count1 = i;
	while (count1 < 7)
	{
		count1++;
		if (board[count1][j] == 0)
		{
			ChessState *state = new ChessState;
			state->board[count1][j] = state->board[i][j];
			state->board[i][j] = 0;
			myStates.push_back(state);
			queen_possible_moves++;
		}
		else if (board[count1][j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[count1][j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			queen_possible_moves++;
			count1 = 7;
		}
		else
		{
			count1 = 7;
		}
	}
	return queen_possible_moves;
}

int ChessState::moveLeft_Queen(int i, int j)
{
	int count1 = j;
	while (count1 < 7)
	{
		count1++;
		if (board[i][count1] == 0)
		{
			ChessState *state = new ChessState;
			state->board[i][count1] = state->board[i][j];
			state->board[i][j] = 0;
			myStates.push_back(state);
			queen_possible_moves++;
		}
		else if (board[i][count1] > 0)
		{
			ChessState *C = new ChessState;
			C->board[i][count1] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			queen_possible_moves++;
			count1 = 7;
		}
		else
		{
			count1 = 7;
		}
	}
	return queen_possible_moves;
}

int ChessState::moveRight_Queen(int i, int j)
{
	int count1 = j;
	while (count1 > 0)
	{
		count1--;
		if (board[i][count1] == 0)
		{
			ChessState *state = new ChessState;
			state->board[i][count1] = state->board[i][j];
			state->board[i][j] = 0;
			myStates.push_back(state);
			queen_possible_moves++;
		}
		else if (board[i][count1] > 0)
		{
			ChessState *C = new ChessState;
			C->board[i][count1] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			queen_possible_moves++;
			count1 = 0;
		}
		else
		{
			count1 = 0;
		}
	}
	return queen_possible_moves;
}

int ChessState::UpperLeftMove_Queen(int i, int j)
{
	int _i = i;
	int _j = j;
	while (_i < 7 && _j < 7)
	{
		_i++; _j++;
		if (board[_i][_j] == 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			queen_possible_moves++;
		}
		else if (board[_i][_j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			queen_possible_moves++;
			_i = 7;
		}
		else
			_i = 7;
	}
	return queen_possible_moves;
}

int ChessState::UpperRightMove_Queen(int i, int j)
{
	int _i = i;
	int _j = j;
	while (_i < 7 && _j > 0)
	{
		_i++; _j--;
		if (board[_i][_j] == 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			queen_possible_moves++;
		}
		else if (board[_i][_j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			queen_possible_moves++;
			_i = 7;
		}
		else
			_i = 7;
	}
	return queen_possible_moves;
}

int ChessState::DownRightMove_Queen(int i, int j)
{
	int _i = i;
	int _j = j;
	while (_i > 0 && _j > 0)
	{
		_i--; _j--;
		if (board[_i][_j] == 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			queen_possible_moves++;
		}
		else if (board[_i][_j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			queen_possible_moves++;
			_i = 0;
		}
		else
			_i = 0;
	}
	return queen_possible_moves;
}

int ChessState::DownLeftMove_Queen(int i, int j)
{
	int _i = i;
	int _j = j;
	while (_i > 0 && _j < 7)
	{
		_i--; _j++;
		if (board[_i][_j] == 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			queen_possible_moves++;
		}
		else if (board[_i][_j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			queen_possible_moves++;
			_i = 0;
		}
		else
			_i = 0;
	}
	return queen_possible_moves;
}

void ChessState::Queen(int i, int j)
{
	if (i < 7)
	{
		moveUp_Queen(i, j);
	}
	if (i > 0)
	{
		moveDown_Queen(i, j);
	}
	if (j < 7)
	{
		moveLeft_Queen(i, j);
	}
	if (j > 0)
	{
		moveRight_Queen(i, j);
	}
	if (i < 7 && j < 7)
	{
		UpperLeftMove_Queen(i, j);
	}
	if (i < 7 && j > 0)
	{
		UpperRightMove_Queen(i, j);
	}
	if (i > 0 && j < 7)
	{
		DownLeftMove_Queen(i, j);
	}
	if (i > 0 && j > 0)
	{
		DownRightMove_Queen(i, j);
	}

}

void ChessState::Rook(int i, int j)
{
	if (i < 7)
	{
		moveUp_Rook(i, j);
	}
	if (i > 0)
	{
		moveDown_Rook(i, j);
	}
	if (j < 7)
	{
		moveLeft_Rook(i, j);
	}
	if (j > 0)
	{
		moveRight_Rook(i, j);
	}
}

int ChessState::moveUp_Rook(int i, int j)
{
	int count1 = i;
	while (count1 < 0)
	{
		count1++;
		if (board[count1][j] == 0)
		{
			ChessState *state = new ChessState;
			state->board[count1][j] = state->board[i][j];
			state->board[i][j] = 0;
			myStates.push_back(state);
			rook_possible_moves++;
		}
		else if (board[count1][j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[count1][j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			rook_possible_moves++;
			count1 = 7;
		}
		else
		{
			count1 = 7;
		}
	}
	return rook_possible_moves;
}

int ChessState::moveDown_Rook(int i, int j)
{
	int count1 = i;
	while (count1 > 0)
	{
		count1--;
		if (board[count1][j] == 0)
		{
			ChessState *state = new ChessState;
			state->board[count1][j] = state->board[i][j];
			state->board[i][j] = 0;
			myStates.push_back(state);
			rook_possible_moves++;
		}
		else if (board[count1][j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[count1][j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			rook_possible_moves++;
			count1 = 0;
		}
		else
		{
			count1 = 0;
		}
	}
	return rook_possible_moves;
}

int ChessState::moveLeft_Rook(int i, int j)
{

	int count1 = j;
	while (count1 < 7)
	{
		count1++;
		if (board[i][count1] == 0)
		{
			ChessState *state = new ChessState;
			state->board[i][count1] = state->board[i][j];
			state->board[i][j] = 0;
			myStates.push_back(state);
			rook_possible_moves++;
		}
		else if (board[i][count1] > 0)
		{
			ChessState *C = new ChessState;
			C->board[i][count1] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			rook_possible_moves++;
			count1 = 7;
		}
		else
		{
			count1 = 7;
		}
	}
	return rook_possible_moves;
}

int ChessState::moveRight_Rook(int i, int j)
{
	int count1 = j;
	while (count1 > 0)
	{
		count1--;
		if (board[i][count1] == 0)
		{
			ChessState *state = new ChessState;
			state->board[i][count1] = state->board[i][j];
			state->board[i][j] = 0;
			myStates.push_back(state);
			rook_possible_moves++;
		}
		else if (board[i][count1] > 0)
		{
			ChessState *C = new ChessState;
			C->board[i][count1] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			rook_possible_moves++;
			count1 = 0;
		}
		else
		{
			count1 = 0;
		}
	}
	return rook_possible_moves;
}

void ChessState::Bishop(int i, int j)
{
	if (i > 0 && j > 0)
	{
		cout << DownRightMove_Bishop(i, j);
	}
	if (i > 0 && j < 7)
	{
		cout << DownLeftMove_Bishop(i, j);
	}
	if (i < 7 && j > 0)
	{
		cout << UpperRightMove_Bishop(i, j);
	}
	if (i < 7 && j < 7)
	{
		cout << UpperLeftMove_Bishop(i, j);
	}
}

int ChessState::UpperLeftMove_Bishop(int i, int j)
{
	int _i = i;
	int _j = j;
	while (_i < 7 && _j < 7)
	{
		_i++; _j++;
		if (board[_i][_j] == 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			bishop_possible_moves++;
		}
		else if (board[_i][_j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			bishop_possible_moves++;
			_i = 7;
		}
		else
			_i = 7;
	}
	return bishop_possible_moves;
}

int ChessState::UpperRightMove_Bishop(int i, int j)
{
	int _i = i;
	int _j = j;
	while (_i < 7 && _j > 0)
	{
		_i++; _j--;
		if (board[_i][_j] == 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			bishop_possible_moves++;
		}
		else if (board[_i][_j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			bishop_possible_moves++;
			_i = 7;
		}
		else
			_i = 7;
	}
	return bishop_possible_moves;
}

int ChessState::DownLeftMove_Bishop(int i, int j)
{
	int _i = i;
	int _j = j;
	while (_i > 0 && _j < 7)
	{
		_i--; _j++;
		if (board[_i][_j] == 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			bishop_possible_moves++;
		}
		else if (board[_i][_j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			bishop_possible_moves++;
			_i = 0;
		}
		else
			_i = 0;
	}
	return bishop_possible_moves;
}

int ChessState::DownRightMove_Bishop(int i, int j)
{
	int _i = i;
	int _j = j;
	while (_i > 0 && _j > 0)
	{
		_i--; _j--;
		if (board[_i][_j] == 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			bishop_possible_moves++;
		}
		else if (board[_i][_j] > 0)
		{
			ChessState *C = new ChessState;
			C->board[_i][_j] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			C->showState();
			bishop_possible_moves++;
			_i = 0;
		}
		else
			_i = 0;
	}
	return bishop_possible_moves;
}

void ChessState::Pawn(int i, int j)
{
	//pawn_possible_moves = 0;
	ChessState * C1 = new ChessState;
	ChessState * C2 = new ChessState;
	ChessState * C3 = new ChessState;
	ChessState * C4 = new ChessState;
	if (i < 7)
	{
		if (PawnCheckForInitial(i, j))
		{
			//one step
			if (board[i + 1][j] == 0)
			{
				C1->board[i + 1][j] = C1->board[i][j];
				C1->board[i][j] = 0;
				myStates.push_back(C1);
				C1->showState();
				pawn_possible_moves++;
			}
			//two step
			if (board[i + 2][j] == 0)
			{
				if (board[i + 1][j] == 0)
				{
					C2->board[i + 2][j] = C2->board[i][j];
					C2->board[i][j] = 0;
					myStates.push_back(C2);
					C2->showState();
					pawn_possible_moves++;
				}
			}
			if (PawnAttackingPair(i, j))
			{
				if (pawn_left == 1)
				{
					C3->board[i + 1][j + 1] = C3->board[i][j];
					C3->board[i][j] = 0;
					myStates.push_back(C3);
					C3->showState();
					pawn_possible_moves++;
				}
				if (pawn_right == 1)
				{
					C4->board[i + 1][j - 1] = C4->board[i][j];
					C4->board[i][j] = 0;
					myStates.push_back(C4);
					C4->showState();
					pawn_possible_moves++;
				}
			}
		}
		else
		{
			//one step
			if (board[i + 1][j] == 0)
			{
				C1->board[i + 1][j] = C1->board[i][j];
				C1->board[i][j] = 0;
				myStates.push_back(C1);
				C1->showState();
				pawn_possible_moves++;
			}
			if (PawnAttackingPair(i, j))
			{
				if (pawn_left == 1)
				{
					C3->board[i + 1][j + 1] = C3->board[i][j];
					C3->board[i][j] = 0;
					myStates.push_back(C3);
					C3->showState();
					pawn_possible_moves++;
				}
				if (pawn_right == 1)
				{
					C4->board[i + 1][j - 1] = C4->board[i][j];
					C4->board[i][j] = 0;
					myStates.push_back(C4);
					C4->showState();
					pawn_possible_moves++;
				}
			}
		}
	}
	else
	{
		//it can behave like queen, bishop, rook, knight
		Queen(i, j);
		Bishop(i, j);
		Rook(i, j);
		Knight(i, j);
	}
	cout << "Pawn" << endl << pawn_possible_moves << endl;
}

bool ChessState::PawnAttackingPair(int i, int j)
{
	pawn_right = 0;
	pawn_left = 0;
	if (j > 0 && j < 7)
	{
		if (board[i + 1][j + 1] > 0)
		{
			pawn_left = 1;
		}
		if (board[i + 1][j - 1] < 0)
		{
			pawn_right = 1;
		}
		if (pawn_left == 1 || pawn_right == 1)
		{
			return 1;
		}
		else
			return 0;
	}
	else
		return 0;
}

bool ChessState::PawnCheckForInitial(int i, int j)
{
	if (i == 1)
	{
		if (j == 0 || j == 1 || j == 2 || j == 3 || j == 4 || j == 5 || j == 6 || j == 7)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

bool ChessState::BishopCheckForInitial(int i, int j)
{
	return false;
}

void ChessState::showPiece(int pieceCode)
{
	if (pieceCode < 0)
		cout << "B";
	else if (pieceCode > 0)
		cout << "W";
	switch (pieceCode)
	{
	case 0:
		cout << "-";
		break;

	case 1:
	case -1:
		cout << "P";
		break;
	case 2:
	case -2:
		cout << "N";
		break;
	case 3:
	case -3:
		cout << "B";
		break;
	case 4:
	case -4:
		cout << "R";
		break;
	case 5:
	case -5:
		cout << "Q";
		break;
	case 6:
	case -6:
		cout << "K";
		break;
	}
	cout << "\t";
}

void ChessState::showState()
{
	cout << endl << "Player To Move:\t";
	if (playerToMove > 0)
		cout << "WHITE" << endl;
	else
		cout << "Black" << endl;

	cout << endl << endl;

	for (int i = 0; i< 8; i++)
	{
		for (int j = 0; j< 8; j++)
		{
			showPiece(board[i][j]);
		}
		cout << endl << endl;
	}
}

ChessState::ChessState()
{
	//ctor

	playerToMove = 1;

	board[0][0] = -4; board[0][1] = -2; board[0][2] = -3; board[0][3] = -5;
	board[0][4] = -6; board[0][5] = -3; board[0][6] = -2; board[0][7] = -4;

	board[1][0] = -1; board[1][1] = -1; board[1][2] = -1; board[1][3] = -1;
	board[1][4] = -1; board[1][5] = -1; board[1][6] = -1; board[1][7] = -1;

	board[2][0] = 0; board[2][1] = 0; board[2][2] = 0; board[2][3] = 0;
	board[2][4] = 0; board[2][5] = 0; board[2][6] = 0; board[2][7] = 0;

	board[3][0] = 0; board[3][1] = 0; board[3][2] = 0; board[3][3] = 0;
	board[3][4] = 0; board[3][5] = 0; board[3][6] = 0; board[3][7] = 0;

	for (int i = 4; i< 8; i++)
	{
		for (int j = 0; j< 8; j++)
		{
			board[i][j] = -board[7 - i][j];
		}
	}
}

void ChessState::Knight(int i, int j)
{
	if (i < 6 && j < 7)
	{
		//UUL
		if (board[i + 2][j + 1] >= 0)
		{
			ChessState *C = new ChessState;
			C->board[i + 2][j + 1] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			knight_possible_moves++;
		}
	}
	if (i < 7 && j < 6)
	{
		//UL
		if (board[i + 1][j + 2] >= 0)
		{
			ChessState *C = new ChessState;
			C->board[i + 1][j + 2] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			knight_possible_moves++;
		}
	}
	if (i < 7 && j > 1)
	{
		//UR
		if (board[i + 1][j - 2] >= 0)
		{
			ChessState *C = new ChessState;
			C->board[i + 1][j - 2] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			knight_possible_moves++;
		}
	}
	if (i < 6 && j > 0)
	{
		//UUR
		if (board[i + 2][j - 1] >= 0)
		{
			ChessState *C = new ChessState;
			C->board[i + 2][j - 1] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			knight_possible_moves++;
		}
	}
	if (i > 1 && j < 7)
	{
		//DDL
		if (board[i - 2][j + 1] >= 0)
		{
			ChessState *C = new ChessState;
			C->board[i - 2][j + 1] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			knight_possible_moves++;
		}
	}
	if (i > 0 && j < 6)
	{
		//DL
		if (board[i - 1][j + 2] >= 0)
		{
			ChessState *C = new ChessState;
			C->board[i - 1][j + 2] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			knight_possible_moves++;
		}
	}
	if (i > 0 && j > 1)
	{
		//DR
		if (board[i - 1][j - 2] >= 0)
		{
			ChessState *C = new ChessState;
			C->board[i - 1][j - 2] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			knight_possible_moves++;
		}
	}
	if (i > 1 && j > 0)
	{
		//DDR
		if (board[i - 2][j - 1] >= 0)
		{
			ChessState *C = new ChessState;
			C->board[i - 2][j - 1] = C->board[i][j];
			C->board[i][j] = 0;
			myStates.push_back(C);
			knight_possible_moves++;
		}
	}

}

void ChessState::kingIncheck(int pieceCode)
{
	int i, j, row, col;
	if (pieceCode > 0)
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				if (pieceCode == -6) //king found
				{
					row = i;
					col = j;
				}
			}
		}
		pieceSafe(row, col);
	}
}

void ChessState::pieceSafe(int row, int col)
{
	//lower right pawn
	if (row + 1 < 8 && col - 1 >= 0 && board[row + 1][col - 1] == 1)
	{
		if (board[row - 1][col] == 0) //escape up
		{
			ChessState *s = new ChessState();
			s->board[row - 1][col] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row][col - 1] == 0) //escape left
		{
			ChessState *s = new ChessState();
			s->board[row][col - 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row][col + 1] == 0) //escape right
		{
			ChessState *s = new ChessState();
			s->board[row][col + 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row + 1][col] == 0) //escape down
		{
			ChessState *s = new ChessState();
			s->board[row + 1][col] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row - 1][col - 1] == 0) //upper left
		{
			ChessState *s = new ChessState();
			s->board[row - 1][col - 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row - 1][col + 1] == 0) //upper right
		{
			ChessState *s = new ChessState();
			s->board[row - 1][col + 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row + 1][col + 1] == 0) //bottom right
		{
			ChessState *s = new ChessState();
			s->board[row + 1][col + 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
	}
	//lower left pawn
	if (row + 1 < 8 && col + 1 < 8 && board[row + 1][col + 1] == 1)
	{
		if (board[row - 1][col] == 0) //escape up
		{
			ChessState *s = new ChessState();
			s->board[row - 1][col] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row][col - 1] == 0) //escape left
		{
			ChessState *s = new ChessState();
			s->board[row][col - 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row][col + 1] == 0) //escape right
		{
			ChessState *s = new ChessState();
			s->board[row][col + 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row + 1][col] == 0) //escape down
		{
			ChessState *s = new ChessState();
			s->board[row + 1][col] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row - 1][col - 1] == 0) //upper left
		{
			ChessState *s = new ChessState();
			s->board[row - 1][col - 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row - 1][col + 1] == 0) //upper right
		{
			ChessState *s = new ChessState();
			s->board[row - 1][col + 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
		if (board[row + 1][col + 1] == 0) //bottom right
		{
			ChessState *s = new ChessState();
			s->board[row + 1][col + 1] = s->board[row][col];
			s->board[row][col] = 0;
			myStates.push_back(s);
		}
	}
	//-------------------------------------------------------------------------
	//upper right check
	for (int i = row - 1, j = col + 1; i >= 0, j<8; i--, j++)
	{
		if (board[i][j] != 0)
		{
			if (board[i][j]<0)
				break;	//this piece is friendly, break

						//piece is black
			if (board[i][j] == 3)
			{
				//attacking queen,bishop,king from upper right
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

			}
			else if (board[i][j] == 5)
			{
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][j] == 6 && row - i == 1)
			{
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

			}
			else
			{
				break;	//non-threatening piece
			}
		}
	}
	//-------------------------------------------------------------------------
	//upper left check
	for (int i = row - 1, j = col - 1; i < 8, j >= 0; i++, j--)
	{
		if (board[i][j] != 0)
		{
			if (board[i][j]<0)
				break;	//this piece is friendly, break

						//piece is black
			if (board[i][j] == 3)
			{
				//attacking queen,bishop,king from upper left
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][j] == 5)
			{
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][j] == 6 && row - i == 1)
			{
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else
			{
				break;	//non-threatening piece
			}
		}
	}
	//--------------------------------------------------------------------
	//lower right check
	for (int i = row + 1, j = col + 1; i<8, j<8; i++, j++)
	{
		if (board[i][j] != 0)
		{
			if (board[i][j]<0)
				break;	//this piece is friendly, break

						//piece is black
			if (board[i][j] == 3)
			{
				//attacking queen,bishop,king from lower right
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][j] == 5)
			{
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][j] == 6 && i - row == 1)
			{
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else
			{
				break;	//non-threatening piece
			}
		}
	}
	//----------------------------------------------------------------------------------------
	//lower left check
	for (int i = row + 1, j = col - 1; i < 8, j >= 0; i++, j--)
	{
		if (board[i][j] != 0)
		{
			if (board[i][j] < 0)
				break;	//this piece is friendly, break

						//piece is black
			if (board[i][j] == 3)
			{
				//attacking queen,bishop,king from lower left
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][j] == 5)
			{
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][j] == 6 && i - row == 1)
			{
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else
			{
				break;	//non-threatening piece
			}
		}
	}
	//--------------------------------------------------------------------------------------
	//Check to the right
	for (int j = col + 1; j < 8; j++)
	{
		if (board[row][j] != 0)
		{
			if (board[row][j]<0)
				break;	//this piece is friendly, break

						//piece is black
			if (board[row][j] == 4)
			{
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[row][j] == 5)
			{
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

			}
			else if (j - col == 1 && board[row][j] == 6)
			{
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

			}
			else
			{
				break;	//non-threatening piece
			}
		}
	}
	//----------------------------------------------------------------------------------------
	//Check to the left
	for (int j = col - 1; j >= 0; j--)
	{
		if (board[row][j] != 0)
		{
			if (board[row][j]<0)
				break;	//this piece is friendly, break

						//piece is black
			if (board[row][j] == 4)
			{
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[row][j] == 5)
			{
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (col - j == 1 && board[row][j] == 6)
			{
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else
			{
				break;	//non-threatening piece
			}
		}
	}
	//---------------------------------------------------------------------------------------
	//Check up
	for (int i = row - 1; i >= 0; i--)
	{
		if (board[i][col] != 0)
		{
			if (board[i][col] < 0)
				break;	//this piece is friendly, break

						//piece is black
			if (board[i][col] == 4)
			{
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][col] == 5)
			{
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (row - i == 1 && board[i][col] == 6)
			{
				if (board[row + 1][col] == 0) //escape down
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

			}
			else
			{
				break;	//non-threatening piece
			}
		}
	}
	//----------------------------------------------------------------------------------------
	//Check down
	for (int i = row + 1; i < 8; i++)
	{
		if (board[i][col] != 0)
		{
			if (board[i][col]<0)
				break;	//this piece is friendly, break

						//piece is black
			if (board[i][col] == 4)
			{
				if (board[row][col - 1] == 0) //escape left
				{
					ChessState *s = new ChessState();
					s->board[row][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row][col + 1] == 0) //escape right
				{
					ChessState *s = new ChessState();
					s->board[row][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col + 1] == 0) //bottom right
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row + 1][col - 1] == 0) //bottom left
				{
					ChessState *s = new ChessState();
					s->board[row + 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (board[i][col] == 5)
			{
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else if (i - row == 1 && board[i][col] == 6)
			{
				if (board[row - 1][col] == 0) //escape up
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
				if (board[row - 1][col - 1] == 0) //upper left
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col - 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}

				if (board[row - 1][col + 1] == 0) //upper right
				{
					ChessState *s = new ChessState();
					s->board[row - 1][col + 1] = s->board[row][col];
					s->board[row][col] = 0;
					myStates.push_back(s);
				}
			}
			else
			{
				break;	//non-threatening piece
			}
		}
	}
	//-------------------------------------------------------------------------------------------
	//knight
	//up L shape
	int i = row - 2;
	if (i >= 0)
	{
		//Left
		int j = col - 1;
		if (j >= 0)
		{
			if (board[i][j] != 0)
			{
				//check to see if piece is a knight
				if (board[i][j] == 2)
				{
					//attacking knight
					if (board[row - 1][col] == 0) //escape up
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col] == 0) //escape down
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col - 1] == 0) //escape left
					{
						ChessState *s = new ChessState();
						s->board[row][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col + 1] == 0) //escape right
					{
						ChessState *s = new ChessState();
						s->board[row][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col - 1] == 0) //upper left
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col + 1] == 0) //bottom right
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col - 1] == 0) //bottom left
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
				}
			}
		}
		//Right
		j = col + 1;
		if (j < 8)
		{
			if (board[i][j] != 0)
			{
				//check to see if piece is a knight
				if (board[i][j] == 2)
				{
					//attacking knight
					if (board[row - 1][col] == 0) //escape up
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col] == 0) //escape down
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col - 1] == 0) //escape left
					{
						ChessState *s = new ChessState();
						s->board[row][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col + 1] == 0) //escape right
					{
						ChessState *s = new ChessState();
						s->board[row][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col + 1] == 0) //upper right
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col + 1] == 0) //bottom right
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col - 1] == 0) //bottom left
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
				}
			}
		}
	}
	//down L shape
	i = row + 2;
	if (i <8)
	{
		//Left
		int j = col - 1;
		if (j >= 0)
		{
			if (board[i][j] != 0)
			{
				//check to see if piece is a knight
				if (board[i][j] == 2)
				{
					//attacking knight
					if (board[row - 1][col] == 0) //escape up
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col] == 0) //escape down
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col] = s->board[row][col];
						board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col + 1] == 0) //upper right
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col - 1] == 0) //upper left
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col - 1] == 0) //bottom left
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col - 1] == 0) //escape left
					{
						ChessState *s = new ChessState();
						s->board[row][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col + 1] == 0) //escape right
					{
						ChessState *s = new ChessState();
						s->board[row][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
				}
			}
		}
		//Right
		j = col + 1;
		if (j < 8)
		{
			if (board[i][j] != 0)
			{
				//check to see if piece is a knight
				if (board[i][j] == 2)
				{
					//attacking knight
					if (board[row - 1][col] == 0) //escape up
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col] == 0) //escape down
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col - 1] == 0) //escape left
					{
						ChessState *s = new ChessState();
						s->board[row][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col + 1] == 0) //escape right
					{
						ChessState *s = new ChessState();
						s->board[row][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col - 1] == 0) //upper left
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col + 1] == 0) //upper right
					{
						board[row - 1][col + 1] = board[row][col];
						board[row][col] = 0;
					}
					if (board[row + 1][col + 1] == 0) //bottom right
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
				}
			}
		}
	}
	//left L shape
	int j = col - 2;
	if (j >= 0)
	{
		//Up
		i = row - 1;
		if (i >= 0)
		{
			if (board[i][j] != 0)
			{
				//check to see if piece is a knight
				if (board[i][j] == 2)
				{
					if (board[row - 1][col] == 0) //escape up
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col] == 0) //escape down
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col - 1] == 0) //escape left
					{
						ChessState *s = new ChessState();
						s->board[row][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col + 1] == 0) //escape right
					{
						ChessState *s = new ChessState();
						s->board[row][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col - 1] == 0) //upper left
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col + 1] == 0) //upper right
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col + 1] == 0) //bottom right
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
				}
			}
		}

		//Down
		i = row + 1;
		if (i<8)
		{
			if (board[i][j] != 0)
			{
				//check to see if piece is a knight
				if (board[i][j] == 2)
				{
					//attacking knight
					if (board[row - 1][col] == 0) //escape up
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col] == 0) //escape down
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col - 1] == 0) //escape left
					{
						ChessState *s = new ChessState();
						s->board[row][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col + 1] == 0) //escape right
					{
						ChessState *s = new ChessState();
						s->board[row][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col + 1] == 0) //upper right
					{
						board[row - 1][col + 1] = board[row][col];
						board[row][col] = 0;
					}
					if (board[row + 1][col + 1] == 0) //bottom right
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col - 1] == 0) //bottom left
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}

				}
			}
		}
	}
	//right L shape
	j = col + 2;
	if (j < 8)
	{
		//Up
		i = row - 1;
		if (i >= 0)
		{
			if (board[i][j] != 0)
			{
				//check to see if piece is a knight
				if (board[i][j] == 2)
				{
					//attacking knight
					if (board[row - 1][col] == 0) //escape up
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col] == 0) //escape down
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col - 1] == 0) //escape left
					{
						ChessState *s = new ChessState();
						s->board[row][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col + 1] == 0) //escape right
					{
						ChessState *s = new ChessState();
						s->board[row][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col - 1] == 0) //upper left
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col + 1] == 0) //upper right
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col + 1] == 0) //bottom right
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}

				}
			}
		}

		//Down
		i = row + 1;
		if (i < 8)
		{
			if (board[i][j] != 0)
			{
				//check to see if piece is a knight
				if (board[i][j] == 2)
				{
					//attacking knight
					if (board[row - 1][col] == 0) //escape up
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col] == 0) //escape down
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col - 1] == 0) //escape left
					{
						ChessState *s = new ChessState();
						s->board[row][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row][col + 1] == 0) //escape right
					{
						ChessState *s = new ChessState();
						s->board[row][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row - 1][col - 1] == 0) //upper left
					{
						ChessState *s = new ChessState();
						s->board[row - 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col + 1] == 0) //bottom right
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col + 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
					if (board[row + 1][col - 1] == 0) //bottom left
					{
						ChessState *s = new ChessState();
						s->board[row + 1][col - 1] = s->board[row][col];
						s->board[row][col] = 0;
						myStates.push_back(s);
					}
				}
			}
		}
	}
}