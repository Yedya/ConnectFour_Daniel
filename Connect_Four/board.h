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
		void digonalChecker(player &player);
		void checkIfWon(string symbol);
		int getBoardSize() const;
		void isColumnFull(int columnNum);
	private:
		int boardSize;
		std::map<int,std::string> mapBoard;
		std::stack<int> columnHeight;
		int player1;
		int player2;
			
};

#endif