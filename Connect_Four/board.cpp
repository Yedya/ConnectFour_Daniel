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
	while(itr->first!=35)
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

	if(posToInsert<0 || posToInsert>6) return; 

	std::map<int,std::string>::iterator itr;
	std::map<int,std::string>::iterator rowToInsert;
	std::map<int,std::string>::iterator posBelow_1;
	posBelow_1 = mapBoard.find(posToInsert+7);
	int endOfColumn = posToInsert+28;

	itr = mapBoard.begin();
	rowToInsert = mapBoard.find(posToInsert);


	string symbolToInsert = " ";
	if(playerName.getPlayerName()=="Player 1")
	{
		symbolToInsert = "| X |";
	}
	else
	{
		symbolToInsert = "| Z |";
	}



	while(itr->first!=3)
	{
		if(posBelow_1->second=="| O |" && posBelow_1->first<=endOfColumn)
		{
			std::advance( posBelow_1, 7 ); //Keep iterating until you reach another already inserted piece, insert above it
			std::advance( rowToInsert, 7 );
			if(rowToInsert->second=="| O |"  && (posBelow_1->second=="| X |" || posBelow_1->second=="| Z |"  ))
			{
				rowToInsert->second =symbolToInsert;
				return;
			}
		}
		else if(rowToInsert->first==posToInsert) 
		{
			cout << "Last  " <<  rowToInsert->first << " " << posBelow_1->second <<   endl;
			rowToInsert->second =symbolToInsert;
			return;
		}
		itr++;
	}
	posBelow_1->second =symbolToInsert;




	
	// is 0,4 empty, is 1,4,  2,4  3,4  4,4  5,4  6,4  7,4
	// 4   3   
	// 11  10
	// 18  17
	// 25  24
	// 32  31  

	// 1   2   
	// 8   9
	// 15  16
	// 22  23
	// 29  30  
}


 

