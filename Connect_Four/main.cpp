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
	while(turns<=34 && player_1.getPlayerStatus()!=true && player_2.getPlayerStatus()!=true )
	{
		cout << "Status " << player_1.getPlayerStatus()  <<endl;
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
				conectFourBoard.digonalChecker();
			}
			else
			{
				conectFourBoard.playerTurn(player_2,pos);
				conectFourBoard.horizVertCheker(player_2);  
				conectFourBoard.digonalChecker();
			}
			conectFourBoard.printMap();
			//conectFourBoard.horizVertCheker();   //* THIS DOESN'T WORK WITHIN YOUR MAIN TURN FUNCTION BECAUSE OF THE "RETURNS" upon insertion 
			//conectFourBoard.digonalChecker();
			turns++;
	}
	//conectFourBoard.playerTurn(player_1,pos);
	//conectFourBoard.playerTurn(player_1,pos);

	//conectFourBoard.playerTurn(player_1,pos2);
	//conectFourBoard.playerTurn(player_1,pos2);
	//conectFourBoard.playerTurn(player_1,pos2);

	//conectFourBoard.playerTurn(player_1,pos3);
	//conectFourBoard.playerTurn(player_1,pos3);
	//

	//conectFourBoard.playerTurn(player_1,pos4);

	system("pause");
	return 0;
}





