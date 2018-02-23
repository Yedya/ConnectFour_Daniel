using namespace std;
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include "board.h"



void main()
{

	board conectFourBoard;

	conectFourBoard.initializeBoard();
	//conectFourBoard.printMap();

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



	int turns = 0;
	bool result = false;
	cout << "\n" <<endl;
	cout << "Player One Goes first" <<endl;
	while(turns<=34 )
	{
		cout << "\n" <<endl;
		cout << "Please Enter a position to Insert [Must be between 1-7]" <<endl;
		cin >> pos;
		pos-=1;
		if(pos<0 || pos>6)
		{
			cout << "Number must be between 1-7...exiting" <<endl;
			continue;
		}
			if(turns%2==0)
			{
				conectFourBoard.playerTurn(player_1,pos);
				conectFourBoard.horizVertCheker(player_1);  
				conectFourBoard.digonalChecker(player_1);
			}
			else
			{
				conectFourBoard.playerTurn(player_2,pos);
				conectFourBoard.horizVertCheker(player_2);  
				conectFourBoard.digonalChecker(player_2);
			}

			if(player_2.getPlayerStatus()==true || player_1.getPlayerStatus()==true )
			{
				break;
			}


			conectFourBoard.printMap();
			turns++;
	}
	cout << "n\ "<<endl;

	if(turns==35 && (player_1.getPlayerStatus()==false || player_2.getPlayerStatus()==false))
	{
		cout << "Board is full, let's play again and nobody won..." <<endl;
		return;
	}


	else if(player_1.getPlayerStatus()==true)
	{
		cout << "Player 1 Wins" <<endl;
		
	}
	else if(player_2.getPlayerStatus()==true)
	{
		cout << "Player 2 Wins" <<endl;
	}
	

	system("pause");

}





