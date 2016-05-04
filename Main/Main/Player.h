#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "WordsOfPlayer.h"

using namespace std;

class Player
{
private:
	int _playerNumber;
	string _playerName;
	int _amountOfPoints = 0;
	char _character;
	WordsOfPlayer _wordsOfPlayer;
	void menuOfWords(char number);
	string _words[4];

public:
	Player();
	void setPlayerNumber(int number);
	int getPlayerNumber();
	void setPlayerName(string name);
	string getPlayerName();
	void playRound(char character);
	void continuePlayingRound();
	string * getWords();
	void addPoints(int amountOfPoints);
	int checkAmountOfPoints();
	~Player();
};

