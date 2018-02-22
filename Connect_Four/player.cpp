#include "player.h"
using namespace std;
#include <iostream>
#include <string>
#include <map>

player::player()
{


}

player::player(std::string &player_Name)
{
	

	playerName = player_Name;
	gameWon = false;
}
	
int player::getPlayerScore() const
{
	return playerScore;
}
	
void player::setScore(int &currentPlayerScore)
{
	playerScore = currentPlayerScore;

}


string player::getPlayerName() const
{

	return playerName;
}

bool player::getPlayerStatus() const
{

	return gameWon;
}

void player::setPlayerStatus(bool currentStatus)
{
	gameWon = currentStatus;

}




