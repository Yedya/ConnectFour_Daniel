#ifndef BOARD_H
#define BOARD_H
using namespace std;
#include <iostream>
#include <string>
#include <map>
#include "player.h"

class board
{
	public:
		board();
		void initializeBoard();
		void printMap();
		void playerTurn(player &playerName,int &posToInsert);

	private:
		int boardSize;
		std::map<int,std::string> mapBoard;

};

#endif