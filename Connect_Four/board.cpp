using namespace std;
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator>
#include "board.h"
#include "player.h"
#include <stack>  

int k=0;
board::board()
{
	std::map<int,std::string> mapBoard;
	std::stack<int> columnHeight;

	//For Initial Piece


	player1 = 0;
	player2 = 0;
	boardSize =34;
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

	//If the player is attempting to insert on the column that is already full
	if(columnHeight.size()!=NULL && tileToInsert->first==columnHeight.top())
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
			//If the tile to insert is free and the tiles below it are occuppied, insert the piece there
            if(tileToInsert->second=="| O |"  && (tileBelow->second=="| X |" || tileBelow->second=="| @ |"  ))
            {
                tileToInsert->second =symbolToInsert;
				if(columnHeight.size()>=1)
				{
					isColumnFull(false,-1);
				}
                return;
            }
        }
		//This is the 5th tile in the column, after this insertion the column is full
        else if(tileToInsert->first==posToInsert) 
        {
			isColumnFull(true,tileToInsert->first);
	        tileToInsert->second =symbolToInsert;
            return;
        }
        columnIterator++;
    }

	if(tileBelow->second=="| O |") // If num turns <=1 
	{
		if(columnHeight.size()>=1)
		{
			isColumnFull(false,-1);
		}
		tileBelow->second =symbolToInsert;
	}
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

	int scoreToWin = 4;

    int countH_P1 = 0;
	int countH_P2 = 0;
    int countV_P1 = 0;
	int countV_P2 = 0;

    int columnEnd = 0;
	int endOfRow =28;
	

	int temp1 =0;
	int temp2= 0;
	int temp3 =0;
	int temp4= 0;

    horizIterFast = mapBoard.find(0);
    horizIterFast2 =mapBoard.find(0);
    int endPoint = 4;
    int startPos =0;
	int distanceToBelowTile = 7;
    int rowEnd =7;

	

	//Could be done in a function
	while(horizIterFast->first<=getBoardSize())
	{
		if(horizIterFast->second=="| X |")
		{	
			countH_P1+=1;
		}
		else
		{
			countH_P1=0;
		}
		if(horizIterFast->second=="| @ |")
		{
			countH_P2+=1;
		}
		else
		{
			countH_P2=0;
		}

		if(countH_P1==scoreToWin || countH_P2==scoreToWin)
		{
			cout << "Connect 4  on  H " << player.getPlayerName();
			player.setPlayerStatus(true);
		}
		if(horizIterFast->first<=6) 
		{
			 columnEnd = ((horizIterFast->first)+(endOfRow));
			 horizIterFast2 =mapBoard.find(horizIterFast->first);

			  // Bug Here, image in paint
			 while(horizIterFast2->first<=columnEnd)
			 {
				if(horizIterFast2->second=="| X |")
				{
					countV_P1+=1;
				}
				else
				{
					countV_P1=0;
				}
				if(horizIterFast2->second=="| @ |")
				{
					countV_P2+=1;
				}
				else
				{
					countV_P2=0;
				}
				
				if(countV_P1==scoreToWin || countV_P2==scoreToWin)
				{
					cout << "Connect 4  on  V " << player.getPlayerName();
					player.setPlayerStatus(true);
				}
				std::advance(horizIterFast2,distanceToBelowTile);
			 }
		}
		horizIterFast++;
	}
}

void board::checkIfWon(string symbol)

{
	
		int p1Score =0;
			
		int p2Score = 0;
		
		if(symbol=="| X |")
		{
			
			p1Score+=1;
		}
		else
		{

			p1Score=0;
		}
		if(symbol=="| @ |")
		{
			
			p2Score+=1;
		}
		else
		{

			p2Score=0;
		}
		cout << "P1  " << p1Score << "P2 " << symbol << endl; //player.getPlayerName();	
		if(p1Score==4 || p2Score==4)
		{
			cout << "Connect 4  on within function" <<endl; //player.getPlayerName();
			
		}
	

}
 
int board::getBoardSize() const
{
	return boardSize;
}

bool board::isColumnFull(bool isTileBelowEmpty,int columnNum)
{
	
	cout << "T:  " << isTileBelowEmpty << endl;
	if(isTileBelowEmpty==true) // Pass in the tile position
	{
		cout << "Pushing " << columnNum << endl;
		columnHeight.push(columnNum);
		
	}
	else
	{
		columnHeight.pop();
	}
	//cout << "Current " << columnHeight.top() << " On " <<columnNum;
	if(columnHeight.size()>=1)
	{
		return true;
	}

	return false;
}