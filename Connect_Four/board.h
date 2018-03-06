#ifndef BOARD_H
#define BOARD_H
using namespace std;
#include <iostream>
#include <string>
#include <map>
#include "player.h"
#include <stack>  
class board
{
	public:
		board();
		void initializeBoard();
		void printMap();
		void playerTurn(player &playerName,int &posToInsert);
		void horizVertCheker(player &player);
		void verticalRecCheck(player &player);
		void checkIfWon(string symbol);
		int getBoardSize() const;
		void isColumnFull(int columnNum);
		void diagonalCheckerRightSide(player &player,int startPoint,int endTile);
		void diagonalCheckerLeftSide(player &player, int startTile,int endTile);
	private:
		int boardSize;
		std::map<int,std::string> mapBoard;
		std::stack<int> columnHeight;
		int player1;
		int player2;
		int diagonalStartPoint;
		string symbolP1;
		string symbolP2;	
};

#endif