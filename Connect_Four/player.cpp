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
}
	
int player::getPlayerScore() const
{
	return playerScore;
}
	
string player::getPlayerName() const
{

	return playerName;
}

void player::setScore(int &currentPlayerScore)
{
	playerScore = currentPlayerScore;

}
