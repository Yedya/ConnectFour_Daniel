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

		void horizontalRecurisveChecker(player &player,int startPos,int horizPos);
		void verticalRecursiveChecker(player &player,int startPos,int vertPos);

		void diagonalCheckerRightSide(player &player,int startPoint,int endTile);
		void diagonalCheckerLeftSide(player &player, int startTile,int endTile);

		void checkIfWon(string symbol);
		void isColumnFull(int columnNum);
		bool isBoardFull();



	private:
		int boardSize;
		int columnLength;
		std::map<int,std::string> mapBoard;
		std::stack<int> columnHeight;

		int player1;
		int player2;
		int diagonalStartPoint;

		string symbolP1;
		string symbolP2;	
		int player1verticalScore;
		int player2verticalScore;

		int player1horizScore;
		int player2horizScore;

};

#endif