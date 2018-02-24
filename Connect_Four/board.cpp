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
	while(iter<=44) 
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
		if(itr->first==7 || itr->first==14  || itr->first==21 || itr->first==28 || itr->first==35)
		{
			cout << "\n";
		}
		cout << itr->second;
		itr++;
	}
}
/*
	Time: 0(N)
	Space: 0(1)
*/
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
	if(tileToInsert->second!="| O |")
	{
		cout << "This column is full, you just wasted a turn "<<endl;
		return;
	}

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
/*
	Time: 0(N)
	Space: 0(1)
*/
void board::digonalChecker(player &player)
{
	std::map<int,std::string>::iterator diagonalIter;
	int startTile =0;
	int countD_P1 = 0;
	int countD_P2 = 0;

	//Add if statements to all whiles?
	// Return true if connect 4

	diagonalIter = mapBoard.find(0);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=24)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}

			std::advance( diagonalIter, 8 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}
	}

	diagonalIter = mapBoard.find(1);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=25)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}

			std::advance( diagonalIter, 8 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}
	}

	diagonalIter = mapBoard.find(2);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=26)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}

			std::advance( diagonalIter, 8 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}
	}

	diagonalIter = mapBoard.find(3);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=27)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}

			std::advance( diagonalIter, 8 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}
	}

	diagonalIter = mapBoard.find(7);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=31)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}

			std::advance( diagonalIter, 8 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}
	}

	diagonalIter = mapBoard.find(8);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=32)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}

			std::advance( diagonalIter, 8 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}
	}

	diagonalIter = mapBoard.find(9);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=33)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}

			std::advance( diagonalIter, 8 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}
	}

	diagonalIter = mapBoard.find(10);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=34)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}

			std::advance( diagonalIter, 6 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}	
	}

	diagonalIter = mapBoard.find(3);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=21)
	{
		if(diagonalIter->second=="| X |")
		{
			countD_P1+=1;
		}
		else if (diagonalIter->second!="| X |")
		{
			countD_P1 = 0;
		}
		if(diagonalIter->second=="| @ |")
		{
			countD_P2+=1;
		}
		else if (diagonalIter->second!="| @ |")
		{
			countD_P2 = 0;
		}

		std::advance( diagonalIter, 6 );
		if(countD_P2==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
		else if(countD_P1==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
	}	
	}

	diagonalIter = mapBoard.find(4);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=22)
	{
		if(diagonalIter->second=="| X |")
		{
			countD_P1+=1;
		}
		else if (diagonalIter->second!="| X |")
		{
			countD_P1 = 0;
		}
		if(diagonalIter->second=="| @ |")
		{
			countD_P2+=1;
		}
		else if (diagonalIter->second!="| @ |")
		{
			countD_P2 = 0;
		}

		std::advance( diagonalIter, 6 );
		if(countD_P2==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
		else if(countD_P1==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
	}	
	}

	diagonalIter = mapBoard.find(5);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=23)
	{
		if(diagonalIter->second=="| X |")
		{
			countD_P1+=1;
		}
		else if (diagonalIter->second!="| X |")
		{
			countD_P1 = 0;
		}
		if(diagonalIter->second=="| @ |")
		{
			countD_P2+=1;
		}
		else if (diagonalIter->second!="| @ |")
		{
			countD_P2 = 0;
		}

		std::advance( diagonalIter, 6 );
		if(countD_P2==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
		else if(countD_P1==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
	}	
	}

	diagonalIter = mapBoard.find(6);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=24)
	{
		if(diagonalIter->second=="| X |")
		{
			countD_P1+=1;
		}
		else if (diagonalIter->second!="| X |")
		{
			countD_P1 = 0;
		}
		if(diagonalIter->second=="| @ |")
		{
			countD_P2+=1;
		}
		else if (diagonalIter->second!="| @ |")
		{
			countD_P2 = 0;
		}

		std::advance( diagonalIter, 6 );
		if(countD_P2==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
		else if(countD_P1==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
	}	
	}

	diagonalIter = mapBoard.find(11);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=29)
	{
		if(diagonalIter->second=="| X |")
		{
			countD_P1+=1;
		}
		else if (diagonalIter->second!="| X |")
		{
			countD_P1 = 0;
		}
		if(diagonalIter->second=="| @ |")
		{
			countD_P2+=1;
		}
		else if (diagonalIter->second!="| @ |")
		{
			countD_P2 = 0;
		}

		std::advance( diagonalIter, 6 );
		if(countD_P2==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
		else if(countD_P1==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
	}	
	}

	diagonalIter = mapBoard.find(12);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=30)
	{
		if(diagonalIter->second=="| X |")
		{
			countD_P1+=1;
		}
		else if (diagonalIter->second!="| X |")
		{
			countD_P1 = 0;
		}
		if(diagonalIter->second=="| @ |")
		{
			countD_P2+=1;
		}
		else if (diagonalIter->second!="| @ |")
		{
			countD_P2 = 0;
		}

		std::advance( diagonalIter, 6 );
		if(countD_P2==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
		else if(countD_P1==4)
		{
			cout << "Connect 4!";
			player.setPlayerStatus(true);
			return;
		}
	}	
	}

	diagonalIter = mapBoard.find(13);
	if(diagonalIter->second!="| O |")
	{
		while(diagonalIter->first<=31)
		{
			if(diagonalIter->second=="| X |")
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!="| X |")
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second=="| @ |")
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!="| @ |")
			{
				countD_P2 = 0;
			}
		
			std::advance( diagonalIter, 6 );
			if(countD_P2==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				cout << "Connect 4!";
				player.setPlayerStatus(true);
				return;
			}
		}
	}
}

/*
	Time: 0(N)
	Space: 0(1)
*/
void board::horizVertCheker(player &player)
{
    std::map<int,std::string>::iterator outerIter;
    std::map<int,std::string>::iterator innerIter;
	std::map<int,std::string>::iterator horizIter;
	std::map<int,std::string>::iterator horizIterFast;
	std::map<int,std::string>::iterator horizIterFast2;

    outerIter = mapBoard.begin();
    innerIter = mapBoard.begin();
	horizIter = mapBoard.find(0);

    int countH_P1 = 0;
	int countH_P2 = 0;
    int countV_P1 = 0;
	int countV_P2 = 0;
    int columnEnd = 0;

    horizIterFast = mapBoard.find(0);
    horizIterFast2 =mapBoard.find(0);
    int endPoint = 4;
    int startPos =0;
    int rowEnd =7;

	while(horizIterFast->first<=34)
	{
		while(horizIterFast2->first<rowEnd)
		{
			if(horizIterFast2->first==endPoint && endPoint<rowEnd)
			{
				endPoint+=1;
				startPos+=1;
				horizIterFast2 =mapBoard.find(startPos);
			}
			if(horizIterFast2->second=="| X |")
			{
				countH_P1+=1;
			}
			else if (horizIterFast2->second!="| X |")
			{
				countH_P1 = 0;
			}

			if(horizIterFast2->second=="| @ |")
			{
				countH_P2+=1;
			}
			else if (horizIterFast2->second!="| @ |")
			{
				countH_P2 = 0;
			}

			if(countH_P1==4)
			{
				cout << "V Connect 4 P1";
				player.setPlayerStatus(true);
				return;
			}
			else if(countH_P2==4)
			{
				cout << "V Connect 4 P2";
				player.setPlayerStatus(true);
				return;
			}

			horizIterFast2++;
		}
        
		std::advance( horizIterFast, 7 );
        
		horizIterFast2 =horizIterFast;
        startPos = horizIterFast->first;
        endPoint = startPos+4;
        rowEnd+=7;

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
			else if(innerIter->second!="| X |")
			{
				countV_P1=0;
			}
			if(innerIter->second=="| @ |")
			{
				countV_P2+=1;
			}
			else if(innerIter->second!="| @ |")
			{
				countV_P2=0;
			}
            std::advance( innerIter, 7 );
        }
		if(countV_P1==4)
		{
			cout << "V Connect 4 P1";
			player.setPlayerStatus(true);
			return;
		}
		else if(countV_P2==4)
		{
			cout << "V Connect 4 P2";
			player.setPlayerStatus(true);
			return;
		}


    outerIter++;
	//Move Our inner iterator to the next column
    innerIter = outerIter;

    }


}
 

