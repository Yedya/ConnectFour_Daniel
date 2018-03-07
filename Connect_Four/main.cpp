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
	regex regex_pattern("-?[0-9]+.?[0-9]+");

	int turns = 0;
	int pos = 0;

	int rightStartPos = 0;
	int rightEndPos = 24;
	int leftStartPos = 3;
	int leftEndPos = 21;


	cout << "\n" <<endl;
	cout << "Player One Goes first" <<endl;


	while(turns<=34)
	{
		cout << "\n" <<endl;
		cout << "Please Enter a position to Insert [Must be between 1-7]" <<endl;
		cin >> pos;
		if(pos>7 || pos<=0)
		{
			cout << "Number must be between 1-7...please try again" <<endl;
			continue;
		}
		pos-=1;

		if(!cin) 
		{
			cout << "Number must be between 1-7...please try again" <<endl;
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			continue;
			// next, request user reinput
		}

			if(turns%2==0)
			{
				conectFourBoard.playerTurn(player_1,pos);
				conectFourBoard.verticalChecker(player_1);  

				conectFourBoard.diagonalCheckerRightSide(player_1,rightStartPos,rightEndPos); 
				conectFourBoard.diagonalCheckerLeftSide(player_1,leftStartPos,leftEndPos);

				conectFourBoard.horizontalRecurisveChecker(player_1,0);
			}
			else
			{
				conectFourBoard.playerTurn(player_2,pos);
				conectFourBoard.verticalChecker(player_2);  

				conectFourBoard.diagonalCheckerRightSide(player_2,rightStartPos,rightEndPos); 
				conectFourBoard.diagonalCheckerLeftSide(player_2,leftStartPos,leftEndPos);

				conectFourBoard.horizontalRecurisveChecker(player_2,0);
			}

			cout << "\n "<<endl;
			conectFourBoard.printMap();
			cout << "\n "<<endl;

			turns++;
			if(player_2.getPlayerStatus()==true || player_1.getPlayerStatus()==true )
			{
				break;
			}
	}

	if(turns==35 && (player_1.getPlayerStatus()==false || player_2.getPlayerStatus()==false))
	{
		cout << "Board is full, let's play again and nobody won..." <<endl;
		return;
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





