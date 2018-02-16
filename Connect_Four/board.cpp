using namespace std;
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include "board.h"
#include "player.h"
board::board()
{
	std::map<int,std::string> mapBoard;
}



/*
	Time: 0(N)
	Space: 0(N)
*/
void board::initializeBoard() 
{
	int iter = 0;
	while(iter!=43)
	{
		mapBoard.insert(std::make_pair(iter,"| O |"));
		iter++;
	}
}

/*
	Time: 0(N)
	Space: 0(1)
*/
void board::printMap()
{
	std::map<int,std::string>::iterator itr;
	itr = mapBoard.begin();
	while(itr->first!=42)
	{
		if(itr->first==7 || itr->first==14  || itr->first==21 || itr->first==28 || itr->first==35 || itr->first==42)
		{
			cout << "\n";
		}
		cout << itr->second;
		itr++;
	}
}

/*
	//Cheack what player is inserting
	// if player 1 = |X| if player 2 use |@|

*/

void board::playerTurn(player &playerName,int &posToInsert)
{
	if(posToInsert<1 || posToInsert>7) return;

	std::map<int,std::string>::iterator itr;
	std::map<int,std::string>::iterator dM;
	std::map<int,std::string>::iterator posBelow_1;
	posBelow_1 = mapBoard.find(posToInsert+7);


	itr = mapBoard.find(posToInsert);
	int posInserted = itr->first;

	int x = 0;
	itr = mapBoard.begin();
	dM = mapBoard.begin();



	while(itr->first!=posInserted+1)
	{
		
		//cout << posBelow_1->second << " G  " << posBelow_1->first <<endl;
		if(posBelow_1->second=="| O |" && posBelow_1->first<=35 )
		{
			cout << "Working " << posBelow_1->first << endl;
			std::advance( posBelow_1, 7 ); //Keep iterating until you reach another already inserted piece, insert above it
			std::advance( dM, 7 );
			cout << "Working |" << dM->first << endl;
			
		}
		else if(posBelow_1->second=="| X |") //Player 1
		{
			
		}
		else if(posBelow_1->second=="| @ |") //Player 2
		{
			
		}
		//std::advance( posBelow_1, 7 );


		if(itr->first==posInserted)
		{
			itr->second ="| X |";
		}

		itr++;




	}
	// Insert at pos 4
	// is 0,4 empty, is 1,4,  2,4  3,4  4,4  5,4  6,4  7,4
	// 4
	// 11
	// 18
	// 25
	// 32



	//int c =0;
	////0(N)
	//for(int k =0;k<rowPos;k++)
	//{
	//	c++;
	//}
	//cout << itr->second.at(c) << " rowToChange" <<endl;
}


 

