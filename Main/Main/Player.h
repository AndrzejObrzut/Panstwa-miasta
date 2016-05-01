#pragma once
#include <iostream>
#include <string>
#include "WordsOfPlayer.h"

using namespace std;

class Player
{
private:
	int _playerNumber;
	string _playerName;
	int _amountOfPoints = 0;
	WordsOfPlayer wordsOfPLayer;
	void menuOfWords(int number);

public:
	Player();
	void setPlayerNumber(int number);
	int getPlayerNumber();
	void setPlayerName(string name);
	string getPlayerName();
	void playRound(char character);
	void addPoints(int amountOfPoints);
	int checkAmountOfPoints();
	~Player();
};

