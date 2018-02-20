using namespace std;
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include "board.h"
int fibonacci(int n) 
{
    if (n <= 1) return n;
    return fibonacci(n - 2) + fibonacci(n - 1);
}
int fibo_iter(int n)
{
    int previous = 1;
    int current = 1;
    int next = 1;
    for (int i = 3; i <= n; ++i) 
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    return next;
}

void printMap(std::map<int,std::string> &boardMap,std::map<int,std::string>::iterator &itr,int &numTiles ) 
{
	itr = boardMap.begin();
	int numRows = 7;
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

void fillMap(std::map<int,std::string> &boardMap,int &numOfTiles)
{
	if(numOfTiles<=1) return;

	int iter = 0;
	while(iter!=numOfTiles+1)
	{
		//cout << iter;
		boardMap.insert(std::make_pair(iter,"|O|"));
		iter++;
	}
}

void printBoard(int rowPos, int columnPos) 
{
	std::map<int,string> columns;
	std::map<int,string> rows;
	string k = "\o/";
	for(int i = 0;i<=4;i++)
	{
		//Rows
		columns.insert(pair<int,string>(i,"|o|"));
		for(int j=0;j<=6;j++)
		{	
			
			
			rows.insert(pair<int,string>(j,"|o|"));
			if(j==rowPos && i==columnPos)
			{
				printf("|X|");
			}
			//else if(j==3 && i==2)
			//{
			//	printf("|O|");
			//}
			else
			{
				printf("|O|");
			}
			//printf("|O|");
		}
		printf( "\n" );
	}
}

void insertPiece(std::map<int,std::vector<int>> m,int rowPos, int columnPos)
{
	std::map<int,std::vector<int>>::iterator itr;
	itr = m.find(columnPos);
	int j = itr->first;
	cout << j << " colToChange"<<endl;

	int c =0;
	//0(N)
	for(int k =0;k<rowPos;k++)
	{
		c++;
	}
	cout << itr->second.at(c) << " rowToChange" <<endl;

}

int main()
{
	std::map<int,std::string> colMap;

	int numRows = 42;
	board conectFourBoard;

	conectFourBoard.initializeBoard();
	conectFourBoard.printMap();

	string playerName1 = "Player 1";
	string playerName2 = "Player 2";
	player player_1(playerName1);
	player player_2(playerName2);
	int pos = 0;
	//conectFourBoard.playerTurn(player_1,pos);
	//conectFourBoard.playerTurn(player_1,pos);
	//conectFourBoard.playerTurn(player_2,pos);
	conectFourBoard.playerTurn(player_1,pos);
	
	
	int pos2 = 1;
	//
	//conectFourBoard.playerTurn(player_1,pos2);
	//conectFourBoard.playerTurn(player_1,pos2);
	//conectFourBoard.playerTurn(player_2,pos2);
	//conectFourBoard.playerTurn(player_1,pos2);
	conectFourBoard.playerTurn(player_1,pos2);
	
	int pos3 = 2;
	int pos4 = 3;
	//conectFourBoard.playerTurn(player_1,pos4);
	conectFourBoard.playerTurn(player_1,pos3);
	conectFourBoard.playerTurn(player_1,pos4);

	conectFourBoard.playerTurn(player_1,pos4);
	conectFourBoard.playerTurn(player_1,pos4);

	cout << "\n"<<endl;
	cout << "\n"<<endl;
	conectFourBoard.printMap();
	cout << "\n" <<endl;
	conectFourBoard.matchChecker();

	system("pause");
	return 0;
}





