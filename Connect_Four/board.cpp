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


board::board()
{
	std::map<int,std::string> mapBoard;
	std::stack<int> columnHeight;

	//For Initial Piece


	player1 = 0;
	player2 = 0;
	boardSize =34;

	symbolP1 = "| X |";
	symbolP2 = "| @ |";
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
        symbolToInsert = symbolP1;
    }
    else
    {
        symbolToInsert = symbolP2;
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
                return;
            }
        }
		//This is the 5th tile in the column, after this insertion the column is full
        else if(tileToInsert->first==posToInsert) 
        {
			isColumnFull(tileToInsert->first);
	        tileToInsert->second =symbolToInsert;
            return;
        }
        columnIterator++;
    }

	if(tileBelow->second=="| O |") // If num turns <=1 
	{
		tileBelow->second =symbolToInsert;
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
    horizIterFast = mapBoard.find(0);
    horizIterFast2 =mapBoard.find(0);

	int scoreToWin = 4;

    int countH_P1 = 0;
	int countH_P2 = 0;
    int countV_P1 = 0;
	int countV_P2 = 0;


	int endOfColumn =28;
	int columnEnd = ((horizIterFast->first)+(endOfColumn));

    int rowEnd = 7;
    int startPos =0;
	int distanceToBelowTile = 7;
    int intialRowEnd = 7;



	while(horizIterFast->first<rowEnd && horizIterFast->first!=34)
	{
		horizIterFast->second = "| V |";
		if(horizIterFast->second==symbolP1)
		{	
			countH_P1+=1;
		}
		else if(horizIterFast->second!=symbolP1)
		{
			countH_P1=0;
		}
		if(horizIterFast->second==symbolP2)
		{
			countH_P2+=1;
		}
		else if(horizIterFast->second!=symbolP2)
		{
			countH_P2=0;
		}
		if(countH_P1==scoreToWin || countH_P2==scoreToWin)
		{
			player.setPlayerStatus(true);
			return;
		}
		while(horizIterFast2->first<=columnEnd)   //Currently Working
		{
				/*horizIterFast2->second = "| V |";*/
				if(horizIterFast2->second==symbolP1)
				{
					countV_P1+=1;
				}
				else if(horizIterFast2->second!=symbolP1)
				{
					countV_P1=0;
				}
				if(horizIterFast2->second==symbolP2)
				{
					countV_P2+=1;
				}
				else if(horizIterFast2->second!=symbolP2)
				{
					countV_P2=0;
				}
				if(countV_P1==scoreToWin || countV_P2==scoreToWin)
				{
					player.setPlayerStatus(true);
					return;
				}
				std::advance(horizIterFast2,distanceToBelowTile);
		}	

		horizIterFast++;
		if(horizIterFast->first<=6)
		{
			//horizIterFast2 =mapBoard.find(horizIterFast->first);
			//columnEnd = ((horizIterFast->first)+(endOfColumn));
		}
		if(horizIterFast->first==intialRowEnd)
		{
			horizIterFast = mapBoard.find(rowEnd);
			rowEnd+=7;
			/*intialRowEnd+=6;*/
		}


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

void board::isColumnFull(int columnNum)
{
		columnHeight.push(columnNum);
}

void board::diagonalCheckerRightSide(player &player, int startTile,int endTile)
{
	
	
	int advanceItrValue = 8;
	int countD_P1 = 0;
	int countD_P2 = 0;
	int nextPos = 7;
	int upperRowLimit = 4;
	int lowerRowLimit = 10;
	int diagonalEnd = 31;


	if(startTile==upperRowLimit)
	{
		startTile= nextPos;
		endTile= diagonalEnd;
	}

	if (startTile==lowerRowLimit) return;
	

	std::map<int,std::string>::iterator diagonalIter;
	diagonalIter = mapBoard.find(startTile);

		while(diagonalIter->first<=endTile)
		{
			if(diagonalIter->second==symbolP1)
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!=symbolP1)
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second==symbolP2)
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!=symbolP2)
			{
				countD_P2 = 0;
			}
			std::advance( diagonalIter, advanceItrValue );
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

	diagonalCheckerRightSide(player,startTile+1,endTile+1); 
	
}

void board::diagonalCheckerLeftSide(player &player, int startTile,int endTile)
{
	
	
	int advanceItrValue = 6;
	int countD_P1 = 0;
	int countD_P2 = 0;
	int nextPos = 11;
	int upperRowLimit = 7;
	int lowerRowLimit = 14;
	int diagonalEnd = 29;

	if(startTile==upperRowLimit)
	{
		startTile= nextPos;
		endTile= diagonalEnd;
	}
	//Special Case for middle diagonal 
	if (startTile==lowerRowLimit)
	{
		startTile = 10;
		endTile =34;
	}

	std::map<int,std::string>::iterator diagonalIter;
	diagonalIter = mapBoard.find(startTile);
	
		while(diagonalIter->first<=endTile)
		{
			if(diagonalIter->second==symbolP1)
			{
				countD_P1+=1;
			}
			else if (diagonalIter->second!=symbolP1)
			{
				countD_P1 = 0;
			}
			if(diagonalIter->second==symbolP2)
			{
				countD_P2+=1;
			}
			else if (diagonalIter->second!=symbolP2)
			{
				countD_P2 = 0;
			}
			std::advance( diagonalIter, advanceItrValue );
			if(countD_P2==4)
			{
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				player.setPlayerStatus(true);
				return;
			}
		}
		
	if (endTile == 34 ) return;
	diagonalCheckerLeftSide(player,startTile+1,endTile+1);
	
}

void board::verticalRecCheck(player &player)
{



}
