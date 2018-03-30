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

	player1 = 0;
	player2 = 0;
	boardSize =34;
	columnLength=28;


	player1verticalScore=0;
	player2verticalScore=0;

	player1horizScore=0;
	player2horizScore=0;

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
	while(iter!=boardSize+1) 
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
	while(itr!=mapBoard.end()) 
	{
		if(itr->first==7 || itr->first==14  || itr->first==21 || itr->first==28)
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

	if(tileBelow->second=="| O |") 
	{
		tileBelow->second =symbolToInsert;
	}
}

void board::isColumnFull(int columnNum)
{
		columnHeight.push(columnNum);
}

bool board::isBoardFull() 
{
	std::map<int,std::string>::iterator itr;
	itr = mapBoard.find(0);

	int count=0;
	int rowEnd = 7;
	
	while(itr->first<rowEnd)
	{
		
		if(itr->second!="| O |")
		{
			count++;
		}
		if(count==rowEnd)
		{
			return true;
			
		}
		itr++;
	}
	return false;


}

/*
	Time: 0(N)
	Space: 0(1)
*/
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
				player.setPlayerStatus(true);
				return;
			}
			else if(countD_P1==4)
			{
				player.setPlayerStatus(true);
				return;
			}
		}

	diagonalCheckerRightSide(player,startTile+1,endTile+1); 
	
}

/*
	Time: 0(N)
	Space: 0(1)
*/
void board::diagonalCheckerLeftSide(player &player, int startTile,int endTile)
{
	
	if (startTile ==23  && endTile == 29 ) return;
	////if (startTile >=23  && endTile == 29 ) return;
	/*if (startTile > 23 && endTile == 23 ) return;*/
	
	int ItrValue = 6;
	int countD_P1 = 0;
	int countD_P2 = 0;
	int nextPos = 11;
	int upperRowLimit = 7;
	int lowerRowLimit = 14;
	int diagonalEnd = 29;

//	if(startTile==upperRowLimit)
//	{
	//	startTile= nextPos;
	//	endTile= diagonalEnd;
//	}
	/* Special Case for middle diagonal 
	if (startTile==lowerRowLimit)
	{
		startTile = 10;
		endTile =34;
	} */
	
	std::map<int,std::string>::iterator diagonalIter;
	diagonalIter = mapBoard.find(startTile);
	if(diagonalIter->first<=endTile)
	{
			diagonalIter->second = "| V |";
			cout << diagonalIter->first << " End Tile "  << endTile << endl;
			diagonalCheckerLeftSide(player,startTile+=ItrValue,endTile); 
	}
	



	if (startTile == 21 )
	{
		startTile=3;
		startTile+=1;
		endTile= startTile*7;
		diagonalCheckerLeftSide(player,startTile,endTile); 
	}

	if (startTile == 28 )
	{
		startTile=4;
		startTile+=1;
		endTile= 23;
		diagonalCheckerLeftSide(player,startTile,endTile); 
	}





	if (startTile == 23 )
	{
		startTile=10;
		startTile+=1;
		endTile= 29;
		cout << endTile << " "<< " " << startTile << endl;
		diagonalCheckerLeftSide(player,startTile,endTile); 
	}

/*
	if (startTile == 29 )
	{
		cout << "Hit" << endTile << endl;
		
		startTile=4;
		startTile+=1;
		endTile= 23;
		cout << endTile << " "<< " " << startTile << endl;
		diagonalCheckerLeftSide(player,startTile,endTile); 
		
	}	*/
}

/*
	Time: 0(N)
	Space: 0(1)
*/
void board::horizontalRecurisveChecker(player &player,int startPos,int horizPos)
{
	std::map<int,std::string>::iterator horizIterator;
	horizIterator = mapBoard.find(horizPos);
	int rowWidth = 6;
	int rowEnd = (startPos)+rowWidth;
	int scoreToWin = 4;

	//Base Case
	if(horizPos>boardSize || startPos>columnLength ||  player.getPlayerStatus()==true) return;
	
	if(horizIterator->first!=rowEnd)
	{
		if(horizIterator->second==symbolP1)
		{
			player1horizScore+=1;
		}
		else if(horizIterator->second!=symbolP1)
		{
			player1horizScore=0;
		}
		else if(horizIterator->second==symbolP2)
		{
			player2horizScore+=1;
		}
		else if(horizIterator->second!=symbolP2)
		{
			player2horizScore=0;
		}

		if( player2horizScore==scoreToWin || player1horizScore==scoreToWin)
		{
			player.setPlayerStatus(true);
			return;
		}

		horizPos+=1;
		horizontalRecurisveChecker(player,startPos,horizPos);
	}

	if(horizIterator->first==rowEnd)
	{
		player1horizScore=0;
		player2horizScore=0;

		startPos+=1;
		horizPos = startPos;
		horizontalRecurisveChecker(player,startPos,horizPos); 
	}
}

/*
	Time: 0(N)
	Space: 0(1)
*/
void board::verticalRecursiveChecker(player &player,int startPos,int vertPos)
{
	std::map<int,std::string>::iterator vertIterator;
    vertIterator =mapBoard.find(vertPos);
	int columnEnd = ((startPos)+(columnLength));

	//Base Case
	if( startPos>6 || vertPos>columnEnd) return;
	int scoreToWin = 4;
    int rowEnd = 7;
	int distanceToBelowTile = 7;

	if(vertIterator->second==symbolP1)
	{
		player1verticalScore+=1;
	}
	else if(vertIterator->second==symbolP2)
	{
		player2verticalScore+=1;
	}

	if( player2verticalScore==scoreToWin || player1verticalScore==scoreToWin)
	{
		player.setPlayerStatus(true);
		return;
	}

	vertPos+=7;
	verticalRecursiveChecker(player,startPos,vertPos);

	if(vertIterator->first==columnEnd)
	{
		player1verticalScore=0;
		player2verticalScore=0;

		startPos+=1;
		vertPos=startPos;
		verticalRecursiveChecker(player,startPos,vertPos);
	}

}


void board::turnTaken(player &player)
{
	int rightStartPos = 0;
	int rightEndPos = 24;
	int leftStartPos = 3;
	int leftEndPos = 21;
	int diagonalStartPoint = 0;
	int verticalIteratorPos =0;

	//diagonalCheckerRightSide(player,rightStartPos,rightEndPos); 
	diagonalCheckerLeftSide(player,leftStartPos,leftEndPos);
	horizontalRecurisveChecker(player,diagonalStartPoint,0); 
	verticalRecursiveChecker(player,diagonalStartPoint,verticalIteratorPos);


}