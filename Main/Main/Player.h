#pragma once
#include <string>
using namespace std;

class Player
{
private:
	int _playerNumber;
	string _playerName;
	int _amountOfPoints;
public:
	Player();
	void setPlayerNumber(int number);
	int getPlayerNumber();
	void setPlayerName(string name);
	string getPlayerName();

	void addPoints(int amountOfPoints);
	int checkAmountOfPoints();
	~Player();
};

