#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
#include <iostream>
#include <string>

class player
{
	public:
		player();
		player(std::string &player_Name, int &player_Score);
		bool player::operator<(const player& userObj) const;
		int getPlayerScore() const;
		string getPlayerName() const;
		void setScore(int &playerScore);

	private:
		std::string playerName;
		int playerScore;

};

#endif