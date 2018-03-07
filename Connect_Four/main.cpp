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

void turnTaken(board conectFourBoard)
{



}



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

	int rightStartPos = 0;
	int rightEndPos = 24;
	int leftStartPos = 3;
	int leftEndPos = 21;

	int inputMin =0;
	int inputMax = 7;

	cout << "\n" <<endl;
	cout << "Player One Goes first" <<endl;


	while(turns<=34)
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

		/* 
			Minus 1 from the pos as our board starts at zero, 
			It's nice UX to have them enter 1-7 as they're visually displayed as 1-7
		*/
		pos-=1;

		if(turns%2==0)
		{
			conectFourBoard.playerTurn(player_1,pos);
			//conectFourBoard.verticalChecker(player_1);  
			conectFourBoard.verticalRecurisveChecker(player_1,0);

			conectFourBoard.diagonalCheckerRightSide(player_1,rightStartPos,rightEndPos); 
			conectFourBoard.diagonalCheckerLeftSide(player_1,leftStartPos,leftEndPos);

			conectFourBoard.horizontalRecurisveChecker(player_1,0);
		}
		else
		{
			conectFourBoard.playerTurn(player_2,pos);
			//conectFourBoard.verticalChecker(player_2);  
			conectFourBoard.verticalRecurisveChecker(player_2,0);

			conectFourBoard.diagonalCheckerRightSide(player_2,rightStartPos,rightEndPos); 
			conectFourBoard.diagonalCheckerLeftSide(player_2,leftStartPos,leftEndPos);

			conectFourBoard.horizontalRecurisveChecker(player_2,0);
		}

		conectFourBoard.printMap();

		turns++;
		if(player_2.getPlayerStatus()==true || player_1.getPlayerStatus()==true )
		{
			break;
		}
	}

	if(turns==35 && (player_1.getPlayerStatus()==false || player_2.getPlayerStatus()==false))
	{
		cout << "Board is full, and nobody won..." <<endl;
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





