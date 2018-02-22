#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
#include <iostream>
#include <string>

class player
{
	public:
		player();
		player(std::string &player_Name);
		int getPlayerScore() const;
		string getPlayerName() const;
		bool getPlayerStatus() const;
		void setPlayerStatus(bool currentStatus);
		void setScore(int &playerScore);

	private:
		std::string playerName;
		std::string playerSymbol;
		bool gameWon;
		int playerScore;

};

#endif