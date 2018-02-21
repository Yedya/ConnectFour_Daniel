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
	cout << "\n";
	itr = mapBoard.begin();
	cout << "\n";
	while(itr->first!=35)
	{
		if(itr->first==7 || itr->first==14  || itr->first==21 || itr->first==28 || itr->first==35 || itr->first==42)
		{
			cout << "\n";
		}

		cout << "| " << itr->first << " |";
		itr++;
	}

}



void board::playerTurn(player &playerName,int &posToInsert)
{

	if(posToInsert<0 || posToInsert>6) return; 

	std::map<int,std::string>::iterator itr;
	std::map<int,std::string>::iterator rowToInsert;
	std::map<int,std::string>::iterator posBelow_1;
	posBelow_1 = mapBoard.find(posToInsert+7);
	int endOfColumn = posToInsert+21;

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



	while(itr->first!=7)
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

	// 0   2   
	// 7   9
	// 14  16
	// 28  23
	// 35  30  

}


void board::digonalChecker()
{
	std::map<int,std::string>::iterator diagonalIter;
	int startTile =0;
	int countD = 0;

	//Add if statements to all whiles?

	diagonalIter = mapBoard.find(0);
	while(diagonalIter->first<=24)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}	

	diagonalIter = mapBoard.find(1);
	while(diagonalIter->first<=25)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}	

	diagonalIter = mapBoard.find(2);
	while(diagonalIter->first<=26)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}

	diagonalIter = mapBoard.find(3);
	while(diagonalIter->first<=27)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}

	diagonalIter = mapBoard.find(7);
	while(diagonalIter->first<=31)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}	

	diagonalIter = mapBoard.find(8);
	while(diagonalIter->first<=32)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}

	diagonalIter = mapBoard.find(9);
	while(diagonalIter->first<=33)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}

	diagonalIter = mapBoard.find(10);
	while(diagonalIter->first<=34)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}	

	diagonalIter = mapBoard.find(3);
	while(diagonalIter->first<=21)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}

	diagonalIter = mapBoard.find(4);
	while(diagonalIter->first<=22)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}

	diagonalIter = mapBoard.find(5);
	while(diagonalIter->first<=23)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}	

	diagonalIter = mapBoard.find(6);
	while(diagonalIter->first<=24)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}	

	diagonalIter = mapBoard.find(11);
	while(diagonalIter->first<=29)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}

	diagonalIter = mapBoard.find(12);
	while(diagonalIter->first<=30)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}

	diagonalIter = mapBoard.find(13);
	while(diagonalIter->first<=31)
	{
		if(diagonalIter->second!="| O |")
		{
			countD+=1;
		}
		else
		{
			countD = 0;
		}
		std::advance( diagonalIter, 8 );
	}	

	if(countD==4)
	{

		cout << "Connect 4!";
		return;
	}

}


void board::horizVertCheker()
{
    std::map<int,std::string>::iterator outerIter;
    std::map<int,std::string>::iterator innerIter;
	std::map<int,std::string>::iterator verIterator;

    outerIter = mapBoard.begin();
    innerIter = mapBoard.begin();
	verIterator = mapBoard.find(0);

    int countD = 0;
    int countH = 0;
    int countV = 0;
    int columnEnd = 0;

	//Horizontol 
	while(verIterator->first!=34)
	{
        if(verIterator->second=="| X |")
        {
            countH+=1;	
        }
		else if(verIterator->second!="| X |")
		{
			countH=0;
		}
		if(countV==4 || countH==4)
		{
			cout << "Connect 4!";
			return;
		}
		verIterator++;
	}
	
	//Vertical 
    while(outerIter->first!=7)
    {
        columnEnd = ((outerIter->first)+28);
        while(innerIter->first<=columnEnd)
        { 
            if(innerIter->second=="| X |")
            {
                countV+=1;	
            }
			else if(innerIter->second!="| X |")
			{
				countV=0;
			}

            //cout << "Inner " << innerIter->first  <<  " Outer " << outerIter->first ;
            std::advance( innerIter, 7 );
        }
		if(countV==4 || countH==4 )
		{
			cout << "Connect 4!";
			return;
		}
    outerIter++;
	//Move Our inner iterator to the next column
    innerIter = outerIter;

    }


}
 

