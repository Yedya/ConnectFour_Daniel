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
	while(iter<=44) // Was 44 in case anything BLOWS UP
	{
		mapBoard.insert(std::make_pair(iter,"| O |"));
		iter++;
	}
	//cout << iter <<endl;
}

/*
	Time: 0(N)
	Space: 0(1)
*/
void board::printMap()
{
	std::map<int,std::string>::iterator itr;
	itr = mapBoard.begin();
	while(itr->first!=35) //35
	{
		if(itr->first==7 || itr->first==14  || itr->first==21 || itr->first==28 || itr->first==35)
		{
			cout << "\n";
		}
		cout << itr->second;
		itr++;
	}
}

void board::playerTurn(player &playerName,int &posToInsert)
{
    std::map<int,std::string>::iterator columnIterator;
    std::map<int,std::string>::iterator tileToInsert;
    std::map<int,std::string>::iterator tileBelow;

    tileBelow = mapBoard.find(posToInsert+7);
	tileToInsert = mapBoard.find(posToInsert);
	columnIterator = mapBoard.begin();
    int endOfColumn = posToInsert+21;

	//If the column is full
	if(tileToInsert->second!="| O |") return;

    string symbolToInsert = " ";
    if(playerName.getPlayerName()=="Player 1")
    {
        symbolToInsert = "| X |";
    }
    else
    {
        symbolToInsert = "| @ |";
    }
	
    while(columnIterator->first!=7)
    {
        if(tileBelow->second=="| O |" && tileBelow->first<=endOfColumn)
        {
            std::advance( tileBelow, 7 ); //Keep iterating until you reach another already inserted piece, insert above it
            std::advance( tileToInsert, 7 );

			//If the tile to insert is free and tiles below it are occuppied, insert the piece there
            if(tileToInsert->second=="| O |"  && (tileBelow->second=="| X |" || tileBelow->second=="| @ |"  ))
            {
                tileToInsert->second =symbolToInsert;
                return;
            }
        }
        else if(tileToInsert->first==posToInsert) 
        {
	        tileToInsert->second =symbolToInsert;
            return;
        }
        columnIterator++;
    }
    tileBelow->second =symbolToInsert;
}

void board::digonalChecker()
{
	std::map<int,std::string>::iterator diagonalIter;
	int startTile =0;
	int countD = 0;

	//Add if statements to all whiles?
	// Return true if connect 4

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

void board::horizVertCheker(player &player)
{
    std::map<int,std::string>::iterator outerIter;
    std::map<int,std::string>::iterator innerIter;
	std::map<int,std::string>::iterator horizIter;

    outerIter = mapBoard.begin();
    innerIter = mapBoard.begin();
	horizIter = mapBoard.find(0);

    int countH_P1 = 0;
	int countH_P2 = 0;
    int countV_P1 = 0;
	int countV_P2 = 0;
    int columnEnd = 0;

	//Horizontol 
	while(horizIter->first<=35)
	{
		if(horizIter->second=="| X |")
		{
			countH_P1+=1;	
		}
		else if(horizIter->second=="| @ |")
		{
			countH_P2+=1;
		}
		else if(horizIter->second=="| O |")
		{
			countH_P1=0;
			countH_P2=0;
		}

		if(countH_P1==4)
		{
			cout << "Connect 4 P1";
			player.setPlayerStatus(true);
			return;
		}
		else if(countH_P2==4)
		{
			cout << "Connect 4 P2";
			player.setPlayerStatus(true);
			return;
		}
		
		horizIter++;
		
	}
	
	//Vertical 
    while(outerIter->first!=7)
    {
        columnEnd = ((outerIter->first)+28);
        while(innerIter->first<=columnEnd)
        { 
            if(innerIter->second=="| X |")
            {
                countV_P1+=1;	
            }
			else if(innerIter->second=="| @ |")
			{
				countV_P2+=1;
			}
			else if(innerIter->second=="| O |")
			{
				countV_P1=0;
				countV_P2=0;
			}
            std::advance( innerIter, 7 );
        }
		if(countV_P1==4)
		{
			cout << "Connect 4 P1";
			player.setPlayerStatus(true);
			return;
		}
		else if(countV_P2==4)
		{
			cout << "Connect 4 P2";
			player.setPlayerStatus(true);
			return;
		}


    outerIter++;
	//Move Our inner iterator to the next column
    innerIter = outerIter;

    }


}
 

