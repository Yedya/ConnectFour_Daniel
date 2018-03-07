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
		void turnTaken(player &player);

		void verticalChecker(player &player);
		void horizontalRecurisveChecker(player &player,int startPos);
		void verticalRecurisveChecker(player &player,int startPos);

		void diagonalCheckerRightSide(player &player,int startPoint,int endTile);
		void diagonalCheckerLeftSide(player &player, int startTile,int endTile);

		void checkIfWon(string symbol);
		int getBoardSize() const;
		void isColumnFull(int columnNum);


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