#include "groupName.h"
#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <random>
using namespace std;

playerGROUP_NAME::playerGROUP_NAME(int playerColor) :chessPlayer(playerColor)
{
	//ctor
	//    this->playerName = "Group Name";

}
int playerGROUP_NAME::evaluateState()
{
	int whiteScore = 0;
	int blackScore = 0;
	ChessState *c = new ChessState;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (c->board[i][j] == -1)
			{
				blackScore += 1;			//black pawn
			}
			if (c->board[i][j] == -2 || c->board[i][j] == -3)
			{
				blackScore += 3;			//black knight or bishop
			}
			if (c->board[i][j] == -4)
			{
				blackScore += 5;			//black rook
			}
			if (c->board[i][j] == -5)
			{
				blackScore += 9;			//black queen
			}
			if (c->board[i][j] == -6)
			{
				blackScore += 10000000;		//black king
			}
			if (c->board[i][j] == 1)
			{
				whiteScore += 1;			//white pawn
			}
			if (c->board[i][j] == 2 || c->board[i][j] == 3)
			{
				whiteScore += 3;			//white knight or bishop
			}
			if (c->board[i][j] == 4)
			{
				whiteScore += 5;			//white rook
			}
			if (c->board[i][j] == 5)
			{
				whiteScore += 9;			//white queen
			}
			if (c->board[i][j] == 6)
			{
				whiteScore += 10000000;		//white king
			}
		}
	}
	return blackScore - whiteScore;			//black player tries to maximize, white player tries to minimize
}
void playerGROUP_NAME::trackBestMoves()
{
	ChessMove *bestMove= new ChessMove();
	int bestMoveScore;
	int numTurns = 0;
	static const int DEPTH = 3;
	int pieceOnBoard = 0;
	vector<ChessState*> possibleBoards = vector<ChessState*>();
	vector<ChessMove*> moves = vector<ChessMove*>();
	ChessState *c = new ChessState();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (c->board[i][j] < 0)
			{
				pieceOnBoard = c->board[i][j];
				if (pieceOnBoard < 0) 
				{
					for (int k = 0; k < 8; k++)
					{
						for (int l = 0; l < 8; l++)
						{
							bool check = c->checkIfLegalToMove(pieceOnBoard,i,j,k,l);//prob here , no function as of yet, to know about "from" move
							if (check == true)
							{
								ChessMove *move = new ChessMove(i, j, k, l);
								moves.push_back(move);
								ChessState *newBoard = new ChessState;
								doMove(newBoard, move);
								possibleBoards.push_back(newBoard);
							}
						}
					}
				}
			}
		}
	}
	bestMove = moves[0];
	bestMoveScore = applyAlphaBetaPruning(possibleBoards[0], std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), DEPTH,false);

	if (numTurns > 0)
	{
		for (int i = 1; i < possibleBoards.size(); i++)
		{
			cout << "Evaluating move: " << moves[i] << endl;
			int j = applyAlphaBetaPruning(possibleBoards[i], std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), DEPTH,false);
			if (j >= bestMoveScore)
			{
				bestMove = moves[i];
				bestMoveScore = j;
			}
		}
	}
	cout << bestMove << endl;
	numTurns++;
	return doMove(c, bestMove);
}

void playerGROUP_NAME::doMove(ChessState *newBoard, ChessMove * move)
{
	// again by calling check and checkmate, it will check if he can move
	//then by calling functions "to" and "from", it 'll move on to the specific position
}

int playerGROUP_NAME::applyAlphaBetaPruning(ChessState *c, int alpha, int beta, int depth, bool color)
{
	cout << "Begin evaluating position: depth-" << depth << endl;
	if (depth == 0)
	{
		int evaluation = evaluateState();
		return evaluation;
	}
	if (color == 0) //false=0
	{
		ChessState *c = new ChessState();
		std::vector<ChessMove*> moves = std::vector<ChessMove*>();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (c->board[i][j] < 0)
				{
					int pieceOnBoard = c->board[i][j];
					if (pieceOnBoard < 0)
					{
						for (int k = 0; k < 8; k++)
						{
							for (int l = 0; l < 8; l++)
							{
								bool check = c->checkIfLegalToMove(pieceOnBoard, i, j, k, l);//prob here , no function as of yet, to know about "from" move
								if (check == true)
								{
									ChessMove *move = new ChessMove(i, j, k, l);
									moves.push_back(move);
								}
							}
						}
					}
				}
			}
		}

		int newBeta = beta;
		for (auto move : moves)
		{
			ChessState *successorBoard = new ChessState;
			doMove(successorBoard, move);
			if (newBeta < applyAlphaBetaPruning(successorBoard, alpha, beta, depth - 1, !color))
			{
				newBeta = newBeta;
			}
			else if (newBeta > applyAlphaBetaPruning(successorBoard, alpha, beta, depth - 1, !color))
			{
				newBeta = applyAlphaBetaPruning(successorBoard, alpha, beta, depth - 1, !color);
			}
			if (newBeta <= alpha)
			{
				break;
			}
		}
		return newBeta;
	}
	else
	{
		std::vector<ChessMove*> moves = std::vector<ChessMove*>();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (c->board[i][j] < 0)
				{
					int pieceOnBoard = c->board[i][j];
					if (pieceOnBoard < 0)
					{
						for (int k = 0; k < 8; k++)
						{
							for (int l = 0; l < 8; l++)
							{
								bool check = c->checkIfLegalToMove(pieceOnBoard, i, j, k, l);//prob here , no function as of yet, to know about "from" move
								if (check == true)
								{
									ChessMove *move = new ChessMove(i, j, k, l);
									moves.push_back(move);
								}
							}
						}
					}
				}
			}
		}


		int newAlpha = alpha;
		for (auto move : moves)
		{
			ChessState *successorBoard=new ChessState;
			doMove(successorBoard, move);
			if (newAlpha > applyAlphaBetaPruning(successorBoard, alpha, beta, depth - 1, !color))
			{
				newAlpha = newAlpha;
			}
			else if (newAlpha < applyAlphaBetaPruning(successorBoard, alpha, beta, depth - 1, !color))
			{
				newAlpha = applyAlphaBetaPruning(successorBoard, alpha, beta, depth - 1, !color);
			}
			if (beta <= newAlpha)
			{
				break;
			}
		}
		return newAlpha;
	}
}
int playerGROUP_NAME::decideMoveUsingMINIMAX(ChessState &gameState, ChessMove &returnMove, unsigned int depth)
{

	int totalMoves = gameState.makeValidMovesList();
	returnMove.From[0] = returnMove.From[1] = 0;
	returnMove.To[0] = returnMove.To[1] = 0;
	if (totalMoves <= 0)
	{
		return -1;
	}
	int selectedMove = totalMoves - 1;

	// Your code goes here

	returnMove.From[0] = gameState.Moves[selectedMove].From[0];
	returnMove.From[1] = gameState.Moves[selectedMove].From[1];
	returnMove.To[0] = gameState.Moves[selectedMove].To[0];
	returnMove.To[1] = gameState.Moves[selectedMove].To[1];

	return selectedMove;
}
