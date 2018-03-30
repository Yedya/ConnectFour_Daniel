using namespace std;
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <array>
#include "board.h"
#include "regex"

void main()
{
	board conectFourBoard;
	conectFourBoard.initializeBoard();
	conectFourBoard.printMap();
	
	string playerName1 = "Player 1";
	string playerName2 = "Player 2";
	player player_1(playerName1);
	player player_2(playerName2);

	int turns = 0;
	int pos = 0;
	int inputMin =0;
	int inputMax = 7;

	cout << "\n" <<endl;
	cout << "Player One Goes first" <<endl;
	cout << "\n" <<endl;
	while(conectFourBoard.isBoardFull()==false)
	{
		cout << "\n" <<endl;
		cout << "Please Enter a position to Insert [Must be between 1-7]" <<endl;
		cin >> pos;

		if(!cin) 
		{
			cout << "Number must be between 1-7...please try again" <<endl;
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			continue;
			// next, request user reinput
		}

		if(pos>inputMax || pos<=inputMin)
		{
			cout << "Number must be between 1-7...please try again" <<endl;
			continue;
		}

		//	Minus 1 from the pos as our board starts at zero, 
		//	It's nice UX to have them enter 1-7 as they're visually displayed as 1-7
		pos-=1;

		if(turns%2==0)
		{
			conectFourBoard.playerTurn(player_1,pos);
			conectFourBoard.turnTaken(player_1);
		}

		else
		{
			conectFourBoard.playerTurn(player_2,pos);
			conectFourBoard.turnTaken(player_2);
		}
		conectFourBoard.printMap();

		turns++;
		if(player_2.getPlayerStatus()==true || player_1.getPlayerStatus()==true )
		{
			break;
		}
	}

	if(conectFourBoard.isBoardFull()==true)
	{
		cout << "\n" <<endl;
		cout << "Board is full, and nobody won..." <<endl;
		//ToDo: Restart game?
	}

	else if(player_1.getPlayerStatus()==true)
	{
		cout << "\n "<<endl;
		cout << "Player 1 Wins" <<endl;
		
	}
	else if(player_2.getPlayerStatus()==true)
	{
		cout << "\n "<<endl;
		cout << "Player 2 Wins" <<endl;
	}
	
	system("pause");
}





