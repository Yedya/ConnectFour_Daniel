using namespace std;
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include "board.h"



int main()
{
	std::map<int,std::string> colMap;

	int numRows = 42;
	board conectFourBoard;

	conectFourBoard.initializeBoard();
	conectFourBoard.printMap();

	string playerName1 = "Player 1";
	string playerName2 = "Player 2";
	player player_1(playerName1);
	player player_2(playerName2);
	int pos = 0;
	int pos2 = 1;
	int pos3 = 2;
	int pos4 = 3;
	int pos5 = 4;
	int pos6 = 5;
	int pos7 = 6;




	conectFourBoard.playerTurn(player_1,pos);
	conectFourBoard.playerTurn(player_1,pos);
	conectFourBoard.playerTurn(player_1,pos);
	conectFourBoard.playerTurn(player_1,pos);

	conectFourBoard.playerTurn(player_1,pos2);
	conectFourBoard.playerTurn(player_1,pos2);
	conectFourBoard.playerTurn(player_1,pos2);

	conectFourBoard.playerTurn(player_1,pos3);
	conectFourBoard.playerTurn(player_1,pos3);
	

	conectFourBoard.playerTurn(player_1,pos4);
	


	//conectFourBoard.playerTurn(player_1,pos4);
	//conectFourBoard.playerTurn(player_1,pos2);
	//conectFourBoard.playerTurn(player_1,pos3);
	//conectFourBoard.playerTurn(player_1,pos5);
	//conectFourBoard.playerTurn(player_1,pos5);

	//conectFourBoard.playerTurn(player_2,pos4);
	//
	//conectFourBoard.playerTurn(player_2,pos3);
	//conectFourBoard.playerTurn(player_2,pos6);
	//conectFourBoard.playerTurn(player_2,pos5);
	//conectFourBoard.playerTurn(player_2,pos6);

	cout << "\n"<<endl;
	cout << "\n"<<endl;
	cout << "\n" <<endl;
	//conectFourBoard.horizVertCheker();
	conectFourBoard.digonalChecker();
	cout << "\n" <<endl;
	conectFourBoard.printMap();
	system("pause");
	return 0;
}





